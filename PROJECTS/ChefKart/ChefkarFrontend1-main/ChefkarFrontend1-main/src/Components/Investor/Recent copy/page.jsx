import React, { useState } from 'react';
import { data } from "./data/data";
import Feature from './components/Feature';
import "./Page.css"
import "animate.css"

function RecPage1() {
  const [selectedUser, setSelectedUser] = useState(data.user0);
  const [activeIndex, setActiveIndex] = useState(null);
  const [animate, setAnimate] = useState(null);

  const handleImageClick = (userData, index) => {
    setSelectedUser(userData);
    setActiveIndex(index);
    setAnimate('animate__animated animate__slideInRight'); 
    setTimeout(() => {
      setAnimate(null); 
    }, 1000); 
  };

  return (
    <div id="topachiver" className="flex flex-col items-center bg-[#ececec] justify-center  pb-10">
      <div className={`${animate}`}>
        <Feature
          p={selectedUser.p}
          h1={selectedUser.h1}
          details={selectedUser.details}
          student={selectedUser.student}
          company={selectedUser.company}
          img={selectedUser.img}
        />
      </div>
      <div className='flex items-center mb-3 gap-5 justify-center flex-wrap'>
        {Object.values(data).map((user, index) => (
          <button role='button' key={index} onClick={() => handleImageClick(user, index)} className="image-button">
            <img
              className={`relative z-10 inline-block h-10 w-10 rounded-full`}
              src={user.img}
              alt={user.img}
            />
          </button>
        ))}
      </div>
   
    </div>
  );
}

export default RecPage1;
