console.log("1");

setTimeout(() => console.log("2"), 0);

Promise.resolve().then(() => console.log("3"));

console.log("4");
/*
This demonstrates the JavaScript event loop:
Synchronous code runs first (1, 4).
Promise callbacks (.then) are microtasks, which run before timers.
setTimeout callbacks are macrotasks, so they run after all pending microtasks.
*/