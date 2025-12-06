import { useParams, Link } from "react-router-dom";
import { useState, useEffect } from "react";
import { useSyllabus } from "../context/SyllabusContext";

interface Subject {
  id: string;
  name: string;
}

export default function SubjectPage() {
  const { subjectId } = useParams();
  const { year } = useSyllabus();
  const [subject, setSubject] = useState<Subject | null>(null);

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

  // Assumption: Standard 5 modules for now, or check if we can list them.
  // In a real app, we'd probably want a manifest per subject.
  const modules = [1, 2, 3, 4, 5]; 

  if (!subject) return <div>Loading or Subject Not Found...</div>;

  return (
    <div className="subject-page">
      <h2>{subject.id}: {subject.name}</h2>
      <div className="modules-list">
        {modules.map(mod => (
          <Link key={mod} to={`/subject/${subjectId}/module/${mod}`} className="card module-card">
            <h3>Module {mod}</h3>
            <p>View Notes</p>
          </Link>
        ))}
      </div>
    </div>
  );
}
