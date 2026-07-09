function getNumber() {
    return new Promise((resolve, reject) => {
        console.log("Doing some work...");
        setTimeout(() => {
            resolve(10);
        }, 2000);

    });
}
//then tabhi chalega jab promise sahi se execute hoga yaha par
getNumber().then((value) => {
    console.log(value);
})
// upar wala case tab jab promise sahi se chal jayega
// kuya hoga agar api ne error return kar diya to 
// promise reject wala case
function divide(a,b){
    return new Promise((resolve, reject) => {
        setTimeout(() => { // timeout set karne se kaam 2 sec baad hoga abb yaha par
            if(b==0){
            reject("zero se divide nahi hota");
        }
        else{
            resolve(a/b);
        }
        }, 2000);
    })
}
divide(10,2)
.then((ans) => { // ye tab chalega jab resolve hoga 
    console.log("division possible hai aur answer :", ans , "hai");
})
.catch((error) => { // ye tab chalega jab reject hoga
    console.log("Division possible nahi hai 0 se ")
})
console.log("")
divide(10,0)
.then((ans) => {
    console.log(ans);
})
.catch((err) => {
    console.log("0 se divide nahi hota !!")
})
// promise chaining using then 
function square(x){
    return new Promise((resolve,reject) => {
        setTimeout(() => {
            resolve(x*x);
        },1000);
    })
}
square(2)
.then((ans) => {
    console.log(ans);
    return square(ans);
})
.then((ans) => {
    console.log(ans);
    return square(ans);
})
.then((ans) => {
    console.log(ans);
})