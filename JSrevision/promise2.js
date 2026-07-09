function step(msg) {
    return new Promise((resolve) => {
        setTimeout(() => {
            console.log(msg);
            resolve();
        }, 1000);
    });
}
// pehle 1 sec baad step 1 print hoga
// wo resolve hogaya to uske baad step 2 print hoga

step("Step 1")
.then(() => step("Step 2"))
.then(() => step("Step 3"));