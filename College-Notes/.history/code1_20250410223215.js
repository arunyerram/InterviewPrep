
function swapCase(str){
    return str.split(" ").
    map(
        char =>  char=== char.toUpperCase()?
            char.toLowerCase():
            .toUpperCase()
    ).
    join(" ");
}

const input = 'THe Quick Bronwn Fox';
console.log(swapCase(input))