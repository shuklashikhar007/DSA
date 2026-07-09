async function getUser(id) {
    try {
        const response = await fetch(
            `https://jsonplaceholder.typicode.com/users/${id}`
        );
        if (!response.ok) {
            throw new Error(`HTTP Error ${response.status}`);
        }
        const user = await response.json();
        console.log(user);
    }
    catch (err) {
        console.log(err.message);
    }
}
getUser(1000);