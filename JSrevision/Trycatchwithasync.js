function login(success){
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if(success){
                resolve("Welcome!")
            }
            else{
                reject("Wrong password hai ji !")
            }
        }, 2000)
    })
}
async function main() {
    try{
        let msg = await login(true);
        console.log(msg);
    }
    catch(err){
        console.log("Error!", err);
    }
}
main();