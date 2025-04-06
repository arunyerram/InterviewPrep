import React from "react";
import Slider from "react-slick";
import { AiFillStar } from "react-icons/ai";

const Testimonials = () => {
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
    {
      id: 4,
      image:
        "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FCook_Testimony_03_abc123.webp&w=1920&q=75",
      text: "Great service! I was happy with how clean and efficient the cook was.",
      name: "राहुल गुप्ता",
    },
    {
      id: 5,
      image:
        "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FCook_Testimony_02_abc456.webp&w=1920&q=75",
      text: "Absolutely loved the dishes prepared by the cook. They exceeded expectations!",
      name: "अंजलि वर्मा",
    },
  ];

  const settings = {
    dots: true,
    infinite: true,
    speed: 500,
    slidesToShow: 3,
    slidesToScroll: 1,
    autoplay: true,
    autoplaySpeed: 3000,
    pauseOnHover: true,
    swipe: true,
    responsive: [
      {
        breakpoint: 1024,
        settings: {
          slidesToShow: 2,
        },
      },
      {
        breakpoint: 640,
        settings: {
          slidesToShow: 1,
        },
      },
    ],
  };

  return (
    <div className="container mx-auto px-4 py-12">
      <h1 className="text-4xl font-bold text-center mb-8">Testimonials</h1>
      <Slider {...settings}>
        {testimonialsData.map((testimonial) => (
          <div key={testimonial.id} className="p-4">
            <div className="bg-green-700 border-4 border-green-400 hover:bg-white rounded-lg p-6 text-center">
              <img
                alt="testimonial"
                className="w-20 h-20 mb-4 object-cover object-center rounded-full border-2 border-gray-200 bg-gray-100 mx-auto"
                src={testimonial.image}
              />
              <p className="leading-relaxed hover:text-black text-white">{testimonial.text}</p>
              <div className="flex justify-center mt-4">
                {[...Array(5)].map((_, i) => (
                  <AiFillStar
                    key={i}
                    className="text-yellow-400 text-lg mx-1"
                  />
                ))}
              </div>
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

export default Testimonials;
