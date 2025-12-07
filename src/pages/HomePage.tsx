import './HomePage.css';
import { useEffect, useState } from "react";
import { Link } from "react-router-dom";

import { useSyllabus } from "../context/SyllabusContext";

interface Subject {
    id: string;
    name: string;
}

export default function HomePage() {
  const { year } = useSyllabus();
  const [subjects, setSubjects] = useState<Subject[]>([]);
  const [searchTerm, setSearchTerm] = useState("");

  useEffect(() => {
    fetch(`/data/${year}.json`)
    .then(res => res.json())
    .then(setSubjects)
    .catch(err => console.error("Failed to load subjects:", err));
  }, [year]);

  const filteredSubjects = subjects.filter(sub => {
    const normalizedSearch = searchTerm.toLowerCase().replace(/\s+/g, '');
    const normalizedId = sub.id.toLowerCase();
    return normalizedId.includes(normalizedSearch) || 
      sub.name.toLowerCase().includes(searchTerm.toLowerCase());
  });

  return (
    <>
      <div className="homepage">

        <h2>Find your subject ({year} Syllabus)</h2>
        <input 
          name="searchBox" 
          placeholder="Search by Code or Name (e.g., MAT 101)" 
          type="text" 
          className="search-box"
          value={searchTerm}
          onChange={(e) => setSearchTerm(e.target.value)}
        />

        <div className="subjects">
          {filteredSubjects.map(sub => (
            <Link 
              key={sub.id}
              to={`/subject/${sub.id}`}
              className="card"
            >
              <h3>{sub.id}</h3>
              <p>{sub.name} <span className="subject-year-badge">{year}</span></p>
            </Link>
          ))}
          {filteredSubjects.length === 0 && (
            <p>No subjects found matching "{searchTerm}"</p>
          )}
        </div>

      </div>
    </>
  );
}
