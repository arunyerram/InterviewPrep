
function swapCase(str){
    return str.split(" ").
    map(
        char =>  char=== char.toUpperCase()?
            char.toLowerCase():
            car.toUpperCase()
    ).
    join(" ");
}

const input = 'THe Quick Bronwn Fox';
console.log(swapCase(input))