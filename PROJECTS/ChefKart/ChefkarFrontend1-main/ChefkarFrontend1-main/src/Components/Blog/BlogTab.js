import React, { useState } from "react";

const TabSwitch = () => {
  const data = [
    {
      id: 1,
      category: "Partner",
      title: "“जहाँ आपको इज़्ज़त नहीं मिले, ChefKart उस घर में आपको कभी नहीं भेजेगी” : अजनहर बीबी शेख़।”",
      date: "June 8, 2023",
      readTime: "3 min",
      image: "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FScreenshot_2023_06_10_at_4_17_36_PM_3a8dfffd4e.png&w=1920&q=75"
    },
    {
      id: 2,
      category: "Partner",
      title: "“Empowering the domestic working community”",
      date: "June 8, 2023",
      readTime: "3 min",
      image: "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FBlog_ZO_03_0008b023df.webp&w=1920&q=75"
    },
    {
      id: 3,
      category: "Must Read",
      title: "Empowering the domestic working community",
      description: "A story of resilience and empowerment...",
      date: "February 10, 2023",
      readTime: "3 min",
      image: "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FBlog_image_82ea3de818.png&w=1920&q=75"
    },
    {
      id: 4,
      category: "Must Read",
      title: "Empowering the domestic working community",
      description: "A story of resilience and empowerment...",
      date: "February 10, 2023",
      readTime: "3 min",
      image: "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FScreenshot_2023_06_24_at_3_54_55_PM_1d2b58b7d7.png&w=1920&q=75"
    },
    {
      id: 5,
      category: "Must Read",
      title: "Empowering the domestic working community",
      description: "A story of resilience and empowerment...",
      date: "February 10, 2023",
      readTime: "3 min",
      image: "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FFood_d7b9aaa238.jpg&w=1920&q=75"
    },
    {
      id: 6,
      category: "Trending",
      title: "ChefKart Revolutionizing Domestic Services",
      description: "A deep dive into how ChefKart is changing the game...",
      date: "April 15, 2023",
      readTime: "5 min",
      image: "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2Fblog_banner_02_c53b8b734b.webp&w=1920&q=75"
    },
    {
      id: 7,
      category: "Trending",
      title: "ChefKart Revolutionizing Domestic Services",
      description: "A deep dive into how ChefKart is changing the game...",
      date: "April 15, 2023",
      readTime: "5 min",
      image: "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FBlog_Banner_1_V6_287615be2c.png&w=1920&q=75"
    },
    {
      id: 8,
      category: "Food Recipe",
      title: "10 Quick Recipes to Try at Home",
      description: "Learn to cook delicious meals in under 30 minutes...",
      date: "May 20, 2023",
      readTime: "8 min",
      image: "https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FSuperfoods_Good_Flour_blog_6b225efd3b.webp&w=1920&q=75"
    }
  ];


  const [activeTab, setActiveTab] = useState("Partner");
  

  const categories = [...new Set(data.map((item) => item.category))];
  
  const filteredData = data.filter((item) => item.category === activeTab);

  return (
    <div className="max-w-7xl mx-auto p-6">
      {/* Tab Buttons */}
      <div className="flex space-x-4 mt-5 mb-6 justify-center items-center">
        {categories.map((category, index) => (
          <button
            key={index}
            onClick={() => setActiveTab(category)}
            className={`px-4 py-2 rounded-lg ${
              activeTab === category
                ? "bg-purple-700 text-white"
                : "bg-gray-200 text-black"
            }`}
          >
            {category}
          </button>
        ))}
      </div>
     
      {/* Content */}
      <div className="grid grid-cols-1  mt-10 md:grid-cols-4 gap-6">
        {filteredData.map((item) => (
          <div
            key={item.id}
            className="bg-white shadow-md mt-10 rounded-lg overflow-hidden"
          >
            <img src={item.image} alt={item.title} className="w-full h-40 object-cover" />
            <div className="p-4">
              <h3 className="text-lg font-bold">{item.title}</h3>
              <p className="text-gray-600 mt-2">{item.description}</p>
              <div className="mt-4 flex justify-between text-sm text-gray-500">
                <span>{item.date}</span>
                <span>{item.readTime}</span>
              </div>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
};

export default TabSwitch;
