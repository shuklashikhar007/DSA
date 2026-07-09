// Javascript ki revison class
console.log("Shikhar Shukla has finally begun the JS revision ")
age = 24;
full_name = "Shikhar Shukla" // khud detect ki ye ek strin hai yaha par
console.log(full_name);
flag = true;
flag = false;
//(1) var 
// global scope variable -> can be edited later on mid execution ( both redeclared and updated)
var num = 20;
console.log(num);
var num = 30;
console.log(num);
//(2) let 
// block scope variable {} -> similar to mutex lock in C++
// cannot be redeclared but can be modified
{
    let number = 50; 
    // let number = 60 -> ye nahi kar sakte hai
    number = 60;
    console.log(number);
}
//console.log(number); // ye print karne par error dega because let ka scope {} iske andar tak hi limited hai
// 3) const 
// ye bhi block {} scope variable hai
// cannot be redeclared nor updated
// non primitive data types 
// Object iska ek example hai 
{
    const obj = {
    full_name : "Shikhar Shukla",
    age : 21,
    cgpa : 8.75,
    ispass : true,
    college : "IIT BHU",
    dept : "Chemical Engineering"
}
    console.log(obj.full_name);  // yaha print hojayega
    console.log(obj.age);
    obj.full_name = "Shreya Shukla";
    console.log(obj.full_name);
    console.log(typeof(obj.full_name));

}
// console.log(obj.full_name); // yaha print nahi hoga
// console.log(obj.age);
// conditonal statements naye concepts 
const pehla = 1;
const dusra = "1";
if(pehla == dusra){
    console.log("value match karti hai !!")
}
if(pehla === dusra){ // ye dono compare karega value as well as data  type
    console.log("value aur type dono match karte hai !! ")
}
else{
    console.log("value match karti hai but type match nahi karti !! ")
}
// ternary operator 
pehla === dusra ? console.log("same value") : console.log("nahi hai same value");
/// loops
// 1) for 2) while 3) do while
for(let i = 1 ; i <= 10 ;i++){
    console.log("TPC")
}
let n = 10;
while(n > 0){
    console.log("Shukla");
    n--;
}
var k = 5;
do{
    console.log("maza aya!")
    k--
}while(k> 0);
try{
{
    //const pata = 10;
}
    console.log("Shikhar Shukla");
   // console.log(pata)
}
catch(error){
    console.log(error);
}
const obja = {
    name : "RAJNI SHUKLA",
    age : 47,
    desgination : " Admin ki mummy ",
    address : "T - 402 Rangoli Greens Jaipur RJ"
};

const dest = {...obja}; // destructuring a objext to make a copy of it
dest.name = "Jitendra Kumar Shukla";
console.log(obja.name);
console.log(dest.name);
let arr = [12,2,0,423,4223];
// JS mai bhi 0 based indexing hoti hain array ke andar
arr.forEach((value,index) => {
    arr[index] = value + index;
});
for(let key in arr){
    console.log(key, " ", arr[key]);
}
console.log(arr);
