// ek GET request in JS
async function getUsers(){
    try{
        console.log("leke ata hu data")
        const response = await fetch("https://jsonplaceholder.typicode.com/users");
        const users = await response.json(); // jo bhi response aya uska pehle json object banayege
        // taki usko acess kar sake ham
        console.log(users)
    }
    catch(err){
        console.log("Error : ", err)
    }
}
getUsers();

