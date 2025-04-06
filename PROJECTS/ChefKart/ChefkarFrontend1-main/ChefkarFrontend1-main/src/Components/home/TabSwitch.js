import React, { useState } from "react";

const TabSwitchComponent = () => {
  const [activeTab, setActiveTab] = useState("singles");

  const singlesContent = (
    <div className="flex flex-col lg:flex-row items-center gap-10">
      {/* Image Section */}
      <div className="w-full lg:w-1/2 flex justify-center">
        <img
          src="https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FSingles_5497580168.webp&w=1920&q=75" // Replace with the actual image path
          alt="For Singles"
          className="rounded-lg shadow-md"
        />
      </div>
      {/* Text Section */}
      <div className="w-full lg:w-1/2 text-center lg:text-left">
        <h2 className="text-3xl font-bold mb-4">No more missing Ghar Ka Khana!</h2>
        <p className="text-gray-600 text-lg">
          Let our cooks bring memories of home to your plate.
        </p>
      </div>
    </div>
  );

  const familiesContent = (
    <div className="flex flex-col lg:flex-row items-center gap-10">
        
      {/* Image Section */}
      <div className="w-full lg:w-1/2 flex justify-center">
        <img
          src="https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FFamily_f0c0d80b42.webp&w=1920&q=75" // Replace with the actual image path
          alt="For Families"
          className="rounded-lg shadow-md"
        />
      </div>
      {/* Text Section */}
      <div className="w-full lg:w-1/2 text-center lg:text-left">
        <h2 className="text-3xl font-bold mb-4">Food catered to every family member!
        !</h2>
        <p className="text-gray-600 text-lg">
        Spend time with your loved ones as our best cooks take care of the cooking.
        </p>
      </div>
    </div>
  );

  return (
    <section className="bg-gray-50 py-16">
      <div className="container mx-auto px-5">
        {/* Tab Navigation */}
        <h1 className="text-5xl  text-black font-bold text-center">Healthy food cooked in your kitchen, <br/>whenever you want!</h1>
        <div className="flex justify-center mb-8 mt-5">
          <button
            className={`px-6 py-3 text-lg font-semibold ${
              activeTab === "singles"
                ? "text-orange-600 border-b-4 border-orange-600"
                : "text-gray-500"
            }`}
            onClick={() => setActiveTab("singles")}
          >
            For Singles
          </button>
          <button
            className={`px-6 py-3 text-lg font-semibold ${
              activeTab === "families"
                ? "text-orange-600 border-b-4 border-orange-600"
                : "text-gray-500"
            }`}
            onClick={() => setActiveTab("families")}
          >
            For Families
          </button>
        </div>

        {/* Content Section */}
        <div>
          {activeTab === "singles" ? singlesContent : familiesContent}
        </div>
      </div>
    </section>
  );
};

export default TabSwitchComponent;
