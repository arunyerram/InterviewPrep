
function swapCase(str){
    return str.split(" ").
    map(
        c ar ==> car == c 
    ).
    join(" ");
}

const input = 'THe Quick Bronwn Fox';
console.log(swapCase(input));