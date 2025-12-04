import { useState } from "react";
import { Link } from "react-router-dom";
import './header.css';

export default function Header() {
  const [isMenuOpen, setIsMenuOpen] = useState(false);

  return(
  <header className="app-header">

      <h2 className="logo">openktu</h2>

      <button 
        className="menu-toggle" 
        onClick={() => setIsMenuOpen(!isMenuOpen)}
        aria-label="Toggle navigation"
      >
        <span className="hamburger-line"></span>
        <span className="hamburger-line"></span>
        <span className="hamburger-line"></span>
      </button>

      <nav className={isMenuOpen ? "open" : ""}>
        <Link to="/" onClick={() => setIsMenuOpen(false)}>about</Link>
        <Link to="/" onClick={() => setIsMenuOpen(false)}>contribute</Link>
        <Link to="/" onClick={() => setIsMenuOpen(false)}>contact</Link>
      </nav>

  </header>
  )

}
