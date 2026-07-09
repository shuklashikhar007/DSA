async function main() {
    try {
        // sari api calls ek sath launch kardo 
        // isse process bhi fast hogi 
        const [usersRes, postsRes] = await Promise.all([
            fetch("https://jsonplaceholder.typicode.com/users"),
            fetch("https://jsonplaceholder.typicode.com/posts")
        ]);
        const users = await usersRes.json();
        const posts = await postsRes.json();
        console.log("Users:", users.length);
        console.log("Posts:", posts.length);
    }
    catch (err) {
        console.log(err);
    }
}
main();