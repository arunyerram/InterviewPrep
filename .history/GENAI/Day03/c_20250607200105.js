function step1(data,cb){
    setTinemout(() => {})
    console.log(data + " step1");
}
function step2(data,cb){
    console.log(data + " step2");
    cb();
}
function step3(data,cb){
    console.log(data + " step3");
    cb();
}