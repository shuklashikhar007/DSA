function task(name, time) {
    return new Promise((resolve,reject) => {
        setTimeout(() => {
            console.log(name, "done");
            resolve(name);
        }, time);
        
    });
}
async function main() {
    let ans = await Promise.all([
        task("A", 3000),
        task("B", 1000),
        task("C", 2000)
    ]);
    console.log(ans);
}
main();