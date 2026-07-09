// JS mai promises likhne ka sundar aur effecient tarika hai ye wala
// async await hi actual production code mai use hota hai
function getNumber(){
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve(100);
        }, 2000);
    })
}
async function main() {
    console.log("waiting..")
    let ans = await getNumber();
    console.log(ans);
    console.log("Finished kaam ")
}
main();
console.log("Program running")
