#include<bits/stdc++.h>
using namespace std;

// ======================
// CUSTOM STRUCT
// ======================

struct Node{
    int x, y, z;
};

// ======================
// SORT COMPARATORS
// ======================

// pair -> second ascending
bool cmpSecondAsc(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

// pair -> second ascending, first descending
bool cmpSecondAscFirstDesc(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

// Node -> x descending, y ascending
bool cmpNode(Node a, Node b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x > b.x;
}

// ======================
// PRIORITY QUEUE COMPARATORS
// ======================

// smallest second element on top
struct MinSecond{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

// largest second element on top
struct MaxSecond{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};

// smallest x on top
struct MinX{
    bool operator()(Node a, Node b){
        return a.x > b.x;
    }
};

// largest x on top
struct MaxX{
    bool operator()(Node a, Node b){
        return a.x < b.x;
    }
};

int main(){

    // ======================
    // SORTING
    // ======================

    vector<int> a = {5,2,8,1,9};

    sort(a.begin(), a.end()); // ascending

    sort(a.begin(), a.end(), greater<int>()); // descending


    vector<pair<int,int>> vp = {
        {1,5},
        {3,2},
        {4,2},
        {2,7}
    };

    sort(vp.begin(), vp.end(), cmpSecondAsc);

    sort(vp.begin(), vp.end(), cmpSecondAscFirstDesc);


    vector<Node> v = {
        {3,5,1},
        {7,2,4},
        {7,1,9}
    };

    sort(v.begin(), v.end(), cmpNode);


    // lambda sort
    sort(vp.begin(), vp.end(), [](auto &a, auto &b){
        return a.first < b.first;
    });


    // ======================
    // PRIORITY QUEUES
    // ======================

    // max heap
    priority_queue<int> maxpq;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minpq;


    // pair max heap (default)
    priority_queue<pair<int,int>> pq1;


    // pair min heap
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq2;


    // smallest second on top
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        MinSecond
    > pq3;


    // largest second on top
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        MaxSecond
    > pq4;


    // custom struct pq
    priority_queue<
        Node,
        vector<Node>,
        MinX
    > pq5;


    priority_queue<
        Node,
        vector<Node>,
        MaxX
    > pq6;

    return 0;
}

/*
important stuff 
// SORT
return true;
// => a comes before b

// PRIORITY QUEUE
return true;
// => a has lower priority than b

*/