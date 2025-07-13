function step1(data,cb){
    setTimeout(() => {
        cb(data + " step1 completed");
    },1000);
    // console.log(data + " step1");
}
function step2(data,cb){
    setTimeout(() => {
        cb(data + " step2 completed");
    },1000);
    // console.log(data + " step2");
}
function step3(data,cb){
    setTimeout(() => {
        cb(data + " step3 completed");
    },1000);
    // console.log(data + " step3");
}

step1("data",r1 => {
    console.log(r1);
    step2(r1, r2 => {
        console.log(r2);
        step3(r2, r3 => {
            console.log(r3);
        });
    }); 
});