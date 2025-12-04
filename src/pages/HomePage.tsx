import './HomePage.css';
import { useEffect, useState } from "react";
import { Link } from "react-router-dom";

interface Subject {
    id: string;
    name: string;
}

export default function HomePage() {

  const [subjects, setSubjects] = useState<Subject[]>([]);

  useEffect(() => {
    fetch("/subjects.json")
    .then(res => res.json())
    .then(setSubjects)
    .catch(err => console.error("Failed to load subjects:", err));
  }, []);

  return (
    <>
      <div className="homepage">

        <h2>Find your subject</h2>
        <input name="searchBox" placeholder="MAT 101" type="text" className="search-box"/>

        <div className="subjects">
          {subjects.map(sub => (
            <Link 
              key={sub.id}
              to={'/notes/$sub.id}'}
              className="card"
            >
              <h3>{sub.id}</h3>
              <p>{sub.name}</p>
            </Link>
          ))}
        </div>

      </div>
    </>
  );
}
