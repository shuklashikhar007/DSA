async function getUser(id) {
    try{
        const response = await fetch(
            `https://jsonplaceholder.typicode.com/users/${id}`
        )
        const data = await response.json(); // await important hai kyoki uske baad 
        // hi ye ek proer Javascript object ban payega
        for(let key in data){
            console.log(key, " ", data[key])
        }
    }
    catch(err){
        console.log(err);
    }
}
getUser(3);