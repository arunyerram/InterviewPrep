// 2. Write a JavaScript program to find the most frequent item of an array.

let arr = [1,2,3,4,5,6,7,8,5,2,4,1,9,10,11,12];

let freqMap = {};
function processInput(){

    for(let i=0;i<arr.length;i++){
        if(freqMap[arr[i]]){
            freqMap[arr[i]]++;
        } else {
            freqMap[arr[i]] = 1;
        }
    }
}
processInput();

console.log(freqMap);





