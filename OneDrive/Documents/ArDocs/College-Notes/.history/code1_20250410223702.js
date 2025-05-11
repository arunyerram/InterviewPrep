
function swapCase(str){
    return str.split("").
    map(
        char =>  char === char.toUpperCase()?
            char.toLowerCase():
            char.toUpperCase()
    ).
    join("");

    let ans;
    for(let it of str){
        
    }

}

const input = 'THe Quick Bronwn Fox';
console.log(swapCase(input))


