
function swapCase(str){
    return str.split("").
    map(
        char =>  char === char.toUpperCase()?
            char.toLowerCase():
            char.toUpperCase()
    ).
    join("");

    var ans = "";
    for(let it of str){
        if(it !== " "){ans += it;
        }
    }
    return ans;
}

const input = 'THe Quick Bronwn Fox';
console.log(swapCase(input))


