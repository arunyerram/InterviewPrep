import React from 'react';
import './Navbar.css';

const Navbar = () => {
  return (
    <nav className="navbar">
      <div className="navbar-logo">
        <h1>MySite</h1>
      </div>
      <ul className="navbar-links">
        <li><a href="#home" className="nav-link">Home</a></li>
        <li><a href="#about" className="nav-link">About</a></li>
        <li><a href="#services" className="nav-link">Services</a></li>
        <li><a href="#contact" className="nav-link">Contact</a></li>
      </ul>
    </nav>
  );
};

export default Navbar;
