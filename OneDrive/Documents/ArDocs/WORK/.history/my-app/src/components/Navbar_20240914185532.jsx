import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import '../CSS/Navbar.css';

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

      <div className={`navbar-links ${menuOpen ? 'active' : ''}`}>
        <Link to="/" className="nav-link">Home</Link>
        <Link to="/about" className="nav-link">About</Link>
        <Link to="/services" className="nav-link">Services</Link>
        <Link to="/contact" className="nav-link">Contact</Link>
      </div>
    </nav>
  );
};

export default Navbar;
