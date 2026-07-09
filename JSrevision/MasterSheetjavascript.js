/*
=====================================================================
        JavaScript Async / Await / Promises - Complete Revision
=====================================================================

This file covers:

1. Call Stack
2. Synchronous vs Asynchronous code
3. setTimeout
4. Promises
5. Promise States
6. Promise Chaining
7. async / await
8. fetch() API
9. Promise.all()
10. Event Loop
11. Microtask Queue
12. Macrotask Queue
13. JS vs C++

=====================================================================
1. JavaScript is Single Threaded
=====================================================================

There is only ONE Call Stack.

Only one function executes at a time.

            Call Stack

        +-------------+
        |             |
        +-------------+

Whenever a function is called,
it gets pushed onto the stack.

Whenever it finishes,
it gets popped.

Exactly like C++.

=====================================================================
*/


function first() {
    console.log("Inside First");
}

function second() {
    first();
    console.log("Inside Second");
}

console.log("===== Call Stack Demo =====");

second();

console.log("Program Continues");


/*
Stack Visualization

main()

↓

push second()

↓

push first()

↓

first() finishes

↓

second() finishes

↓

main()

*/


/*
=====================================================================
2. Synchronous Execution
=====================================================================
*/

console.log("\n===== Synchronous Code =====");

console.log("A");
console.log("B");
console.log("C");

/*

Output

A
B
C

Every line waits for previous line.

*/


/*
=====================================================================
3. Asynchronous Execution
=====================================================================
*/

console.log("\n===== setTimeout Demo =====");

console.log("Start");

setTimeout(() => {
    console.log("Timer Finished");
}, 2000);

console.log("End");

/*

Output

Start
End

(after 2 sec)

Timer Finished


Important:

JavaScript DOES NOT WAIT.

Instead,

JS

↓

Browser Runtime

↓

Starts timer

↓

Returns immediately

*/


/*
=====================================================================
4. Creating a Promise
=====================================================================
*/

function getNumber() {

    return new Promise((resolve, reject) => {

        console.log("Working...");

        setTimeout(() => {

            resolve(100);

        }, 2000);

    });

}

console.log("\n===== Promise Demo =====");

let promise = getNumber();

console.log(promise);

/*

Initially

Promise { pending }

After 2 sec

Promise { 100 }

*/


/*
=====================================================================
5. Using then()
=====================================================================
*/

getNumber()
.then(value => {

    console.log("Resolved Value =", value);

});

console.log("Program keeps running...");

/*

Output

Working...

Program keeps running...

(after 2 sec)

Resolved Value = 100

*/


/*
=====================================================================
6. Promise Rejection
=====================================================================
*/

function divide(a, b) {

    return new Promise((resolve, reject) => {

        if (b == 0)
            reject("Division by Zero");

        else
            resolve(a / b);

    });

}

divide(10, 2)
.then(ans => console.log(ans))
.catch(err => console.log(err));

divide(10, 0)
.then(ans => console.log(ans))
.catch(err => console.log(err));


/*
=====================================================================
7. Promise Chaining
=====================================================================
*/

function square(x) {

    return new Promise(resolve => {

        setTimeout(() => {

            resolve(x * x);

        }, 1000);

    });

}

square(2)

.then(ans => {

    console.log(ans);

    return square(ans);

})

.then(ans => {

    console.log(ans);

    return square(ans);

})

.then(ans => {

    console.log(ans);

});

/*

Output

4

16

256

*/


/*
=====================================================================
8. async / await
=====================================================================
*/

async function asyncDemo() {

    console.log("\n===== Async Await =====");

    let value = await getNumber();

    console.log(value);

}

asyncDemo();

console.log("Main Thread Continues");

/*

Output

Working...

Main Thread Continues

(after 2 sec)

100

Notice

await pauses ONLY asyncDemo()

Entire JavaScript DOES NOT STOP.

*/


/*
=====================================================================
9. Real API Call
=====================================================================

Works in Browser / Node 18+

*/

async function getUser(id) {

    try {

        const response = await fetch(

            `https://jsonplaceholder.typicode.com/users/${id}`

        );

        if (!response.ok)
            throw new Error("HTTP Error " + response.status);

        const data = await response.json();

        console.log("\n===== User Data =====");

        for (let key in data)
            console.log(key, ":", data[key]);

    }

    catch(err) {

        console.log(err);

    }

}

// Uncomment

// getUser(3);


/*
IMPORTANT

fetch()

↓

returns Promise

↓

await

↓

response object

↓

response.json()

↓

returns another Promise

↓

await

↓

JavaScript Object

*/


/*
=====================================================================
10. Promise.all()
=====================================================================
*/

async function parallelRequests() {

    const [users, posts] = await Promise.all([

        fetch("https://jsonplaceholder.typicode.com/users"),

        fetch("https://jsonplaceholder.typicode.com/posts")

    ]);

    const userData = await users.json();

    const postData = await posts.json();

    console.log(userData.length);

    console.log(postData.length);

}

// parallelRequests();


/*
Both requests run simultaneously.

Instead of

Request A

↓

wait

↓

Request B

Promise.all

Request A
Request B

↓

wait for both

Much faster.

*/


/*
=====================================================================
11. Event Loop
=====================================================================
*/

console.log("\n===== Event Loop Demo =====");

console.log("1");

setTimeout(() => {

    console.log("2");

}, 0);

Promise.resolve()

.then(() => {

    console.log("3");

});

console.log("4");

/*

Output

1

4

3

2


Reason

Call Stack executes first

↓

Promise callback goes to Microtask Queue

↓

Timer callback goes to Macrotask Queue

↓

Event Loop

↓

Microtask first

↓

Macrotask later

*/


/*
=====================================================================
12. Microtask Queue
=====================================================================

Contains

Promise.then()

Promise.catch()

Promise.finally()

await continuation

FIFO Queue

------------------

A

B

C

------------------

Output

A

B

C

NOT a Heap.

*/


/*
=====================================================================
13. Macrotask Queue
=====================================================================

Contains

setTimeout()

setInterval()

DOM Events

MessageChannel

FIFO Queue

*/


/*
=====================================================================
14. Is Promise Queue a Min Heap?
=====================================================================

NO.

Promise Queue

↓

FIFO

The browser decides WHEN a promise resolves.

As soon as a Promise settles,

its callback gets ENQUEUED.

Whichever settles first,

gets inserted first.

Example

p1 -> 5 sec

p2 -> 2 sec

After 2 sec

Queue

[p2 callback]

After 5 sec

Queue

[p1 callback]

No sorting occurs.

*/


/*
=====================================================================
15. Timers
=====================================================================

Internally,

the browser/runtime often maintains timers
using a Min Heap.

Example

setTimeout(A,5000)

setTimeout(B,1000)

setTimeout(C,3000)

Heap

      B

    /   \

   A     C

When timer expires

↓

move callback

↓

Macrotask Queue

*/


/*
=====================================================================
16. JS vs C++
=====================================================================

C++

download();

cout<<"Done";

Thread blocks.


JavaScript

await fetch(url);

Function pauses.

Thread becomes FREE.

Other JS executes.

Network finishes.

Function resumes.

Huge Difference.


C++ usually needs

std::thread

std::future

std::async

JavaScript hides all this behind

Promise

async

await

*/


/*
=====================================================================
17. Complete Flow
=====================================================================

                JavaScript

                     |

                     V

              Call Stack

                     |

                     V

        Browser / Node Runtime

      --------------------------

      Timers

      Network

      File System

      --------------------------

             |            |

             |            |

      Promise Settled   Timer Finished

             |            |

             |            |

             V            V

      Microtask Queue   Macrotask Queue

              \          /

               \        /

                Event Loop

                     |

                     V

              Call Stack


Rules

1. Execute synchronous code.

2. If stack empty

Run ALL Microtasks.

3. Then run ONE Macrotask.

4. Repeat forever.

*/


/*
=====================================================================
Interview Takeaways
=====================================================================

✔ JavaScript is single threaded.

✔ One Call Stack.

✔ fetch() returns Promise immediately.

✔ response.json() ALSO returns Promise.

✔ await pauses only current async function.

✔ Browser handles timers & network.

✔ Event Loop schedules callbacks.

✔ Promise callbacks → Microtask Queue.

✔ setTimeout callbacks → Macrotask Queue.

✔ Microtasks execute before Macrotasks.

✔ Promise Queue is FIFO.

✔ Timer management may use Min Heap internally.

✔ JavaScript achieves concurrency using
   Event Loop + Runtime,
   NOT by creating new threads for every async task.

=====================================================================
*/