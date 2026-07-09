// yaha pe ham mimic karege ek real website ko using 
// async functions
console.log("start");
setTimeout(() => {
    console.log("ham timeout ke andar hai !!");
}, 2000);// yaha after , time out likhte hai
console.log("end");
// promise ek esi value hoti hai jo baad mai availaible hoti hai 
function getNumber() {
    return new Promise((resolve, reject) => {
        console.log("Doing some work...");
        setTimeout(() => {
            resolve(10);
        }, 200);

    });
}
let p = getNumber();
console.log(p);