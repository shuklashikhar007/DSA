/*
1️⃣ Using mpp[key] to check existence
❌ Wrong
if (mpp[x]) { ... }


or

if (mpp[key] == 0) { ... }

🚨 Problem

mpp[key] creates the key if it doesn’t exist

Pollutes the map

Changes map size silently

✅ Correct
if (mpp.find(key) != mpp.end())


or

if (mpp.count(key))

🔴 2️⃣ Forgetting duplicate keys overwrite values
mpp[a] = i;


If a appears again → old index is lost.

❌ Problem

Dangerous in Two Sum, frequency problems, ranges

✅ Fix

Store vector of indices

unordered_map<int, vector<int>> mpp;


Or insert after checking

if (!mpp.count(a)) mpp[a] = i;
3️⃣ Using same element twice (Two Sum classic bug)
req = x - a;
if (mpp.count(req)) ...


If req == a, you may use the same index twice

✅ Fix

Search before insert

Or check indices:

if (mpp.count(req) && mpp[req] != i)

🔴 4️⃣ Printing result but continuing execution
❌ Wrong
cout << ans << endl;
break;
cout << "IMPOSSIBLE";

🚨 Problem

Output is printed even after success

✅ Fix
return 0;


or use a flag

🔴 5️⃣ Using unordered_map blindly in CSES / CF
🚨 Problem

Can TLE due to hacking or poor hashing

✅ Fixes

Use map if constraints allow

Or add hash protection:

unordered_map<long long, int> mpp;
mpp.reserve(n);
mpp.max_load_factor(0.7);

🔴 6️⃣ Forgetting that map is ordered, unordered_map is not
❌ Wrong assumption
for (auto x : mpp) { ... } // assumes sorted

✅ Rule
Container	Order
map	Sorted
unordered_map	Random
🔴 7️⃣ Using map when array is enough
❌ Overkill
map<int,int> freq;


when range is small.

✅ Better
vector<int> freq(100001);

🔴 8️⃣ Erasing while iterating incorrectly
❌ Wrong
for (auto it : mpp) {
    if (it.second == 0)
        mpp.erase(it.first);
}

✅ Correct
for (auto it = mpp.begin(); it != mpp.end(); ) {
    if (it->second == 0)
        it = mpp.erase(it);
    else
        ++it;
}

🔴 9️⃣ Using wrong data type for key
❌ Bug
map<int,int> mpp;


when values go up to 1e18.

✅ Fix
map<long long,int> mpp;

🔴 🔟 Forgetting that count() is O(1) / O(log n)

map.count() → O(log n)

unordered_map.count() → O(1) avg

Use accordingly.

🧠 Golden Rules (Remember these 💡)

🔹 Check before insert
🔹 Never use mpp[key] for existence check
🔹 Return immediately after printing answer
🔹 Beware of duplicates
🔹 Choose map vs unordered_map wisely

*/