
function processStrings() {
    let str1 = "The Quick Brown Fox";
    // let str2 = "";
    // let input =  prompt("Enter a");

    // let upper1 = str1.toUpperCase();
    // let lower2 = str1.toLowerCase();
    // cin>>str
    // console.log(upper1);
    // console.log(lower2);    

    let toggleCase = (str) => 
        str.split("").map(char => 
            char === char.toUpperCase() ? char.toLowerCase() : char.toUpperCase()
        ).join("");

    // console.log("Uppercase of first string:", upper1);
    // console.log("Lowercase of second string:", lower2);
    // console.log(toggleCase(str1));
    
    // console.log(toggleCase(str2));
}

processStrings();
