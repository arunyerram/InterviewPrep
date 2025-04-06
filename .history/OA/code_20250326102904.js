
function processStrings() {
    let str1 = "The Quick Brown Fox";
    let toggleCase = (str) => 
        str.split("").map(char => 
            char === char.toUpperCase() ? char.toLowerCase() : char.toUpperCase()
        ).join("");
    
    var ans = "";
    for(let i=0;i<str1.length;i++){
        if(str1[i] != " "){
            ans = ans + str1[i];
        }
    }
    console.log(toggleCase(ans));
}

processStrings();
