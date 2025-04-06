/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./src/**/*.{js,jsx,ts,tsx}"
  ],
  content: ["./src/**/*.{js,jsx,ts,tsx}"],
  theme: {
    extend: {
      color:{
        "blue":"#3333cc",
        "red":"#ff0000",
        "secondary":"#555",
        "primaryBG":"#f2f2f2",
      },
      fontFamily:{
        "primary":['Public Sans',"sans-serif"]
      },
    },
  },
  plugins: [],
}

