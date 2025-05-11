
function swapCase(str){
    return str.split(" ").
    map(
        c ar ==> c ar === car.toUpperCase()?
            char.toLowerCase():
            car.toUpperCase();
    ).
    join(" ");
}

const input = 'THe Quick Bronwn Fox';
console.log(swapCase(input));