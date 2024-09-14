import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import './components/Navbar.css';

const Navbar = () => {
  const [menuOpen, setMenuOpen] = useState(false);

  const toggleMenu = () => {
    setMenuOpen(!menuOpen);
  };

  return (
    <nav className="navbar">
      <div className="navbar-logo">
        <h1>MySite</h1>
      </div>

      <div className="menu-icon" onClick={toggleMenu}>
        ☰
      </div>

      <ul className={`navbar-links ${menuOpen ? 'active' : ''}`}>
        <li><Link to="/" className="nav-link">Home</Link></li>
        <li><Link to="/about" className="nav-link">About</Link></li>
        <li><Link to="/services" className="nav-link">Services</Link></li>
        <li><Link to="/contact" className="nav-link">Contact</Link></li>
      </ul>
    </nav>
  );
};

export default Navbar;
