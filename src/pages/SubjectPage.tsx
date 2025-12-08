import { useParams, NavLink } from "react-router-dom";
import { useState, useEffect } from "react";
import ReactMarkdown from 'react-markdown';
import remarkGfm from 'remark-gfm';
import 'github-markdown-css/github-markdown.css';
import { useSyllabus } from "../context/SyllabusContext";
import './SubjectPage.css';

interface Subject {
  id: string;
  name: string;
}

export default function SubjectPage() {
  const { subjectId, moduleId } = useParams();
  const { year } = useSyllabus();
  const [subject, setSubject] = useState<Subject | null>(null);
  const [markdownContent, setMarkdownContent] = useState("");
  const [modules, setModules] = useState<number[]>([1, 2, 3, 4, 5]);

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
          setModules(data.modules);
        }
      })
      .catch(() => {
        // Fallback or keep default
        console.log(`No manifest found for ${subjectId}, using default modules.`);
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
    const fileName = moduleId ? `module${moduleId}.md` : `intro.md`;
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
  }, [subjectId, moduleId]);

  // Assumption: Standard 5 modules for now, or check if we can list them.
  // In a real app, we'd probably want a manifest per subject.
  // const modules = [1, 2, 3, 4, 5]; // Removed in favor of state

  if (!subject) return <div>Loading or Subject Not Found...</div>;

  return (
    <div className="subject-page">
      <h2>{subject.id}: {subject.name}</h2>
      <div className="main-block">
        <div className="modules-list">
          {modules.map(mod => (
            <NavLink 
              key={mod} 
              to={`/subject/${subjectId}/module/${mod}`} 
              className={({ isActive }) => `card module-card${isActive ? ' active' : ''}`}
            >
              <h3>Module {mod}</h3>
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
