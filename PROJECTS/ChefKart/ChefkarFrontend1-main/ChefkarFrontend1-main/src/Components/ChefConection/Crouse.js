import React, { useState, useEffect } from "react";

const Carousel = () => {
  const slides = [
    {
      title: "हुनर से पैसे कमाएँ। ",
      description:
        "अपने खाना बनाने की प्रतिभा को एक नई शुरुआत दें और इसके माध्यम से पैसे कमाएँ।",
      bgImage:
        "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FJoin_as_chef_hero_banner_01_f31e87e92e.webp&w=1920&q=75",
    },
    {
      title: "समाज का नज़रिया बदलें ",
      description:
        "देश में कुक की परिभाषा और उनके लिए दृष्टिकोण बदलने में हमारी मदद करें।",
      bgImage:
        "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FJoin_as_chef_hero_banner_03_e679e84c56.webp&w=1920&q=75",
    },
    {
      title: "ChefKart का हिस्सा बनें ",
      description:
        "हमसे जुड़े 4500 से भी ज़्यादा कुक्स का हिस्सा बनें और अपने कौशल को आगे बढ़ाएँ।",
      bgImage:
        "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FJoin_as_chef_hero_banner_02_6c8df4e377.webp&w=1920&q=75",
    },
 
  ];

  const [currentSlide, setCurrentSlide] = useState(0);

  // Auto slide effect
  useEffect(() => {
    const interval = setInterval(() => {
      setCurrentSlide((prev) => (prev === slides.length - 1 ? 0 : prev + 1));
    }, 3000); // Change slide every 3 seconds

    return () => clearInterval(interval); // Cleanup on component unmount
  }, [slides.length]);

  return (
    <div className="relative w-full h-screen">
      {/* Slide */}
      <div
        className="w-full h-full flex items-center text-white bg-cover bg-center transition-all duration-500"
        style={{
          backgroundImage: `url(${slides[currentSlide].bgImage})`,
        }}
      >
        {/* Text Section */}
        <div className="w-full md:w-1/2 p-10 md:p-16 rounded-r-lg ml-4">
          <h2 className="text-2xl md:text-4xl font-bold mt-3">
            {slides[currentSlide].title}
          </h2>
          <p className="text-base md:text-xl mt-4">
            {slides[currentSlide].description}
          </p>

          <button className="bg-orange-500 text-white font-bold text-lg md:text-xl px-8 py-4 rounded-md mt-5 shadow-lg hover:bg-orange-600 hover:shadow-xl transition-all duration-300">
            ChefKart से जुड़ें
          </button>
        </div>
      </div>

      {/* Indicators */}
      <div className="absolute bottom-6 left-1/2 transform -translate-x-1/2 flex justify-center space-x-2">
        {slides.map((_, index) => (
          <button
            key={index}
            onClick={() => setCurrentSlide(index)}
            className={`h-3 w-3 rounded-full ${
              currentSlide === index ? "bg-gray-800" : "bg-gray-400"
            }`}
          ></button>
        ))}
      </div>
    </div>
  );
};

export default Carousel;
