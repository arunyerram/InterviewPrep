import React from "react";
import Slider from "react-slick";

const Testimonial1 = () => {
  const testimonialsData = [
    {
      id: 1,
      image:
        "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FCook_Testimony_06_b42754596c.webp&w=1920&q=75",
      text: "Pretty impressed by the personalised approach. The cook prepared delicious & nutritious homemade food according to my specific dietary needs and preferences. Will definitely book again!",
      name: "शिवानंद मिश्रा",
    },
    {
      id: 2,
      image:
        "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FCook_Testimony_05_55cf1d4be3.webp&w=1920&q=75",
      text: "बेटे के इलाज के लिए पैसों की बहुत ज़रूरत थी | इस कठिन समय में मुझे ChefKart ने ना सिर्फ़ आर्थिक सहायता दी बल्कि छुट्टियाँ लेने में भी बहुत सहयोग दिखाया |",
      name: "हफ़िज़ीयद्दीन मियां",
    },
    {
      id: 3,
      image:
        "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FCook_Testimony_04_d6bb1266ae.webp&w=1920&q=75",
      text: "मैं हमेशा से चाहती थी कि मेरी बेटी को अपनी शिक्षा के बल पर एक अच्छी नौकरी मिले। जब मैंने ChefKart में ये चिंता जताई तो मेरी बेटी के हुनर से प्रभावित होकर उसे अपनी कंपनी में नौकरी दी।",
      name: "पूनम चंदेलिया",
    },
    
  ];

  // Slider settings
  const settings = {
    dots: true, // Show dots for navigation
    infinite: true, // Infinite scrolling
    speed: 500, // Transition speed in ms
    slidesToShow: 3, // Number of testimonials visible at a time
    slidesToScroll: 1, // Number of testimonials to scroll per swipe
    autoplay: true, // Enable auto-slide
    autoplaySpeed: 3000, // Auto-slide interval in ms
    pauseOnHover: true, // Pause auto-slide when hovering
    swipe: true, // Enable mouse and touch swipe
    responsive: [
      {
        breakpoint: 1024, // Below 1024px
        settings: {
          slidesToShow: 2, // Show 2 testimonials
        },
      },
      {
        breakpoint: 640, // Below 640px
        settings: {
          slidesToShow: 1, // Show 1 testimonial
        },
      },
    ],
  };

  return (
    <div className=" mx-auto px-4 py-12 bg-[#e5e5e5]">
      <h1 className="text-4xl font-bold text-center mb-8">Don’t take our word for it</h1>
      <Slider {...settings}>
        {testimonialsData.map((testimonial) => (
          <div key={testimonial.id} className="p-4 mt-8">
            <div className="bg-green-700  border-4  border-green-400 hover:bg-white  rounded-lg p-6 text-center">
              <img
                alt="testimonial"
                className="w-20 h-20 mb-4 object-cover object-center rounded-full border-2 border-gray-200 bg-gray-100 mx-auto"
                src={testimonial.image}
              />
              <p className="leading-relaxed hover:text-black text-white">{testimonial.text}</p>
              <span className="inline-block h-1 w-10 rounded bg-indigo-500 mt-6 mb-4"></span>
              <h2 className="text-white font-medium title-font tracking-wider text-sm">
                {testimonial.name}
              </h2>
            </div>
          </div>
        ))}
      </Slider>
    </div>
  );
};

export default Testimonial1;
