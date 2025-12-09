import { useParams, NavLink } from "react-router-dom";
import { useState, useEffect } from "react";
import ReactMarkdown from "react-markdown";
import remarkGfm from "remark-gfm";
import "github-markdown-css/github-markdown.css";
import { useSyllabus } from "../context/SyllabusContext";
import "./SubjectPage.css";

interface Subject {
  id: string;
  name: string;
}

interface ModuleItem {
  id: string;
  name: string;
  fileName: string;
}

export default function SubjectPage() {
  const { subjectId, moduleId } = useParams();
  const { year } = useSyllabus();
  const [subject, setSubject] = useState<Subject | null>(null);
  const [markdownContent, setMarkdownContent] = useState("");
  
  const generateDefaultModules = (): ModuleItem[] => [1, 2, 3, 4, 5].map(i => ({
    id: i.toString(),
    name: `Module ${i}`,
    fileName: `module${i}.md`
  }));

  const [modules, setModules] = useState<ModuleItem[]>(generateDefaultModules);

  useEffect(() => {
    if (!subjectId) return;

    // Fetch manifest for dynamic modules
    fetch(`/data/notes/${subjectId}/manifest.json`)
      .then(res => {
        if (!res.ok) throw new Error("Manifest not found");
        return res.json();
      })
      .then(data => {
        if (data.modules && Array.isArray(data.modules)) {
          const newModules: ModuleItem[] = data.modules.map((m: any) => {
            // Handle legacy/simple format (numbers or strings)
            if (typeof m === "number" || typeof m === "string") {
              return {
                id: m.toString(),
                name: `Module ${m}`,
                fileName: `module${m}.md`
              };
            }
            // Handle new object format
            return {
              id: (m.id || m.file).toString(),
              name: m.name || m.file,
              fileName: m.file
            };
          });
          setModules(newModules);
        }
      })
      .catch(() => {
        // Fallback to defaults if manifest is missing (important when switching subjects)
        console.log(`No manifest found for ${subjectId}, using default modules.`);
        setModules(generateDefaultModules());
      });
  }, [subjectId]);

  useEffect(() => {
    // Find subject name from the JSON
    fetch(`/data/${year}.json`)
      .then(res => res.json())
      .then((data: Subject[]) => {
        const sub = data.find(s => s.id.toLowerCase() === subjectId?.toLowerCase());
        if (sub) setSubject(sub);
      })
      .catch(console.error);
  }, [subjectId, year]);

  useEffect(() => {
    // Determine which file to fetch
    let fileName = "intro.md";

    if (moduleId) {
      const activeModule = modules.find(m => m.id === moduleId);
      if (activeModule) {
        fileName = activeModule.fileName;
      } else {
        // Fallback if module is not in the list (e.g., direct link before manifest loads)
        fileName = `module${moduleId}.md`;
      }
    }
    
    const path = `/data/notes/${subjectId}/${fileName}`;

    fetch(path)
      .then(res => {
        if (!res.ok) throw new Error("Content not found");
        return res.text();
      })
      .then(text => setMarkdownContent(text))
      .catch(err => {
        console.error(err);
        setMarkdownContent(`Error loading content: ${err.message}. \n\n (File: ${path})`);
      });
  }, [subjectId, moduleId, modules]);

  if (!subject) return <div>Loading or Subject Not Found...</div>;

  return (
    <div className="subject-page">
      <h2>{subject.id}: {subject.name}</h2>
      <div className="main-block">
        <div className="modules-list">
          {modules.map(mod => (
            <NavLink
              key={mod.id}
              to={`/subject/${subjectId}/module/${mod.id}`}
              className={({ isActive }) => `card module-card${isActive ? " active" : ""}`}
            >
              <h3>{mod.name}</h3>
              <p>View Notes</p>
            </NavLink>
          ))}
        </div>

        <div className="main-content markdown-body">
          <ReactMarkdown remarkPlugins={[remarkGfm]}>
            {markdownContent}
          </ReactMarkdown>
        </div>
      </div>
    </div>
  );
}
