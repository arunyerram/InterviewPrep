import React from "react";
import { AiFillStar } from "react-icons/ai";

const Testimonial = () => {
  return (
    <div>
      <section className="text-gray-600 body-font flex flex-col justify-center items-center">
        <div className="container px-5 py-24 mx-auto flex flex-col items-center">
          <div className="flex flex-wrap justify-center -m-4">
            {/* Testimonial 1 */}
            <div className="lg:w-1/3 lg:mb-0 mb-6 p-4">
              <div className="h-full text-center bg-green-600 rounded-lg">
                <img
                  alt="testimonial"
                  className="w-20 mt-5 h-20 mb-8 object-cover object-center rounded-full inline-block border-2 border-gray-200 bg-gray-100"
                  src="https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FCook_Testimony_06_b42754596c.webp&w=1920&q=75"
                />
                <p className="leading-relaxed text-white">
                  "बेटी के इलाज के दौरान मैंने जो भी सहायता मांगी, मुझे मिली। मेरे कठोर समय में मुझे परिवार की तरह संभाला, इसके लिए ChefKart की जितनी भी प्रशंसा की जाए कम है।"
                </p>
                {/* 5-Star Rating */}
                <div className="flex justify-center mt-4">
                  {[...Array(5)].map((_, i) => (
                    <AiFillStar key={i} className="text-yellow-400 text-lg" />
                  ))}
                </div>
                <span className="inline-block h-1 w-10 rounded bg-indigo-500 mt-6 mb-4"></span>
                <h2 className="text-white font-medium mb-4 title-font tracking-wider text-sm">
                  शिवानंद मिश्रा
                </h2>
              </div>
            </div>

            {/* Testimonial 2 */}
            <div className="lg:w-1/3 lg:mb-0 mb-6 p-4">
              <div className="h-full text-center bg-green-600 rounded-lg">
                <img
                  alt="testimonial"
                  className="w-20 mt-5 h-20 mb-8 object-cover object-center rounded-full inline-block border-2 border-gray-200 bg-gray-100"
                  src="https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FCook_Testimony_05_55cf1d4be3.webp&w=1920&q=75"
                />
                <p className="leading-relaxed text-white">
                  "बेटे के इलाज के लिए पैसों की बहुत ज़रूरत थी | इस कठिन समय में मुझे ChefKart ने ना सिर्फ़ आर्थिक सहायता दी बल्कि छुट्टियाँ लेने में भी बहुत सहयोग दिखाया |"
                </p>
                {/* 5-Star Rating */}
                <div className="flex justify-center mt-4">
                  {[...Array(5)].map((_, i) => (
                    <AiFillStar key={i} className="text-yellow-400 text-lg" />
                  ))}
                </div>
                <span className="inline-block h-1 w-10 rounded bg-indigo-500 mt-6 mb-4"></span>
                <h2 className="text-white font-medium mb-4 title-font tracking-wider text-sm">
                  हफ़िज़ीयद्दीन मियां
                </h2>
              </div>
            </div>

            {/* Testimonial 3 */}
            <div className="lg:w-1/3 lg:mb-0 p-4">
              <div className="h-full text-center bg-green-600 rounded-lg">
                <img
                  alt="testimonial"
                  className="w-20 mt-5 h-20 mb-8 object-cover object-center rounded-full inline-block border-2 border-gray-200 bg-gray-100"
                  src="https://thechefkart.com/_next/image?url=https%3A%2F%2Fchefkart-strapi-media.s3.ap-south-1.amazonaws.com%2FCook_Testimony_04_d6bb1266ae.webp&w=1920&q=75"
                />
                <p className="leading-relaxed text-white">
                  "मैं हमेशा से चाहती थी कि मेरी बेटी को अपनी शिक्षा के बल पर एक अच्छी नौकरी मिले। जब मैंने ChefKart में ये चिंता जताई तो मेरी बेटी के हुनर से प्रभावित होकर उसे अपनी कंपनी में नौकरी दी।"
                </p>
                {/* 5-Star Rating */}
                <div className="flex justify-center mt-4">
                  {[...Array(5)].map((_, i) => (
                    <AiFillStar key={i} className="text-yellow-400 text-lg" />
                  ))}
                </div>
                <span className="inline-block h-1 w-10 rounded bg-indigo-500 mt-6 mb-4"></span>
                <h2 className="text-white font-medium mb-4 title-font tracking-wider text-sm">
                  पूनम चंदेलिया
                </h2>
              </div>
            </div>
          </div>
        </div>
      </section>
    </div>
  );
};

export default Testimonial;
