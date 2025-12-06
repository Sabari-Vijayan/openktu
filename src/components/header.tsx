import { useState } from "react";
import { Link } from "react-router-dom";
import './header.css';
import { useSyllabus } from "../context/SyllabusContext";

export default function Header() {
  const [isMenuOpen, setIsMenuOpen] = useState(false);
  const { year, setYear } = useSyllabus();

  return(
  <header className="app-header">

      <h2 className="logo"><Link to="/">openktu</Link></h2>

      <div className="header-controls">
        <select 
          value={year} 
          onChange={(e) => setYear(e.target.value as '2019' | '2024')}
          className="year-selector"
        >
          <option value="2024">2024 Syllabus</option>
          <option value="2019">2019 Syllabus</option>
        </select>

        <button 
          className="menu-toggle" 
          onClick={() => setIsMenuOpen(!isMenuOpen)}
          aria-label="Toggle navigation"
        >
          <span className="hamburger-line"></span>
          <span className="hamburger-line"></span>
          <span className="hamburger-line"></span>
        </button>
      </div>

      <nav className={isMenuOpen ? "open" : ""}>
        <Link to="/" onClick={() => setIsMenuOpen(false)}>about</Link>
        <Link to="/" onClick={() => setIsMenuOpen(false)}>contribute</Link>
        <Link to="/" onClick={() => setIsMenuOpen(false)}>contact</Link>
      </nav>

  </header>
  )

}
