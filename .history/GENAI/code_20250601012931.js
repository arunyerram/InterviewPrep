

// AIzaSyAhojqkST3ZTGBfZNdSileFRBpLW4OviWQ

import { GoogleGenAI } from "@google/genai";

const ai = new GoogleGenAI({ apiKey: "AIzaSyAhojqkST3ZTGBfZNdSileFRBpLW4OviWQ" });

async function main() {
  const response = await ai.models.generateContent({
    model: "gemini-2.0-flash",
    contents: [
        {
            role : "user",
            parts : [{text :"I am Arun"}]
        }
    ]
  });
  console.log(response.text);
}

await main();