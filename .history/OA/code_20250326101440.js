
function processStrings() {
    let str1 = prompt();
    let str2 = prompt();

    let upper1 = str1.toUpperCase();
    let lower2 = str2.toLowerCase();

    let toggleCase = (str) => 
        str.split("").map(char => 
            char === char.toUpperCase() ? char.toLowerCase() : char.toUpperCase()
        ).join("");

    console.log("Uppercase of first string:", upper1);
    console.log("Lowercase of second string:", lower2);
    console.log("Toggled first string:", toggleCase(str1));
    console.log("Toggled second string:", toggleCase(str2));
}

processStrings();
