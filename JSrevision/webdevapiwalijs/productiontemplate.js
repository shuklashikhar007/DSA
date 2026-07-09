async function getData(url) {
    try{
        const response = await fetch(url);
        if(!response.ok){
            throw new Error(`HTTP Error ${response.status}`);   
        }
        return await response.json();
    }
    catch(error){
        console.log(error);
        return null;
    }
}
async function main() {
    const users = await getData(
        "https://jsonplaceholder.typicode.com/users"
    );
    if(users){
        console.log(users);
    }
}
main();