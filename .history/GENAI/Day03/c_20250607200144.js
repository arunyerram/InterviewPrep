function step1(data,cb){
    setTinemout(() => {
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
    console.log(data + " step3");
    cb();
}