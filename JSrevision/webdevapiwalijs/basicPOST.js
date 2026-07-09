async function createPost() {
    try {
        const response = await fetch(
            "https://jsonplaceholder.typicode.com/posts",
            {
                method: "POST",
                headers: {
                    "Content-Type": "application/json"
                },
                body: JSON.stringify({
                    title: "Learning Async Await",
                    body: "This is my first API call",
                    userId: 1
                })
            }
        );

        const data = await response.json();

        console.log(data);
    }
    catch (err) {
        console.log(err);
    }
}

createPost();