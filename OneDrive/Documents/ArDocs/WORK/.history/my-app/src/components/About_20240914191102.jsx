import React from 'react';
import Navbar from './Navbar';

const Home = () => {
  return (
    <div style={{ paddingTop: '80px' }}> 
      <Navbar />
      <h1>Welcome to the Home Page</h1>
      <p>This is the content of the About US page.</p>
    </div>
  );
};

export default Home;
