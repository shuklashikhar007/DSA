#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int blsize = sqrt(n);
    int nblocks = (n+blsize-1)/blsize;
    vector<int>blocks(nblocks,INT_MAX);
    // store the min of each block in a seprate array 
    for(int i=0;i<n;i++){
        blocks[i/blsize] = min(blocks[i/blsize],a[i]);
    }
    vector<int>ans;
    while (m--)
    {
        int ret = INT_MAX;
        int t,u,v;
        cin >>t>> u >> v;
        if(t==1){ // agar point update query hai to 
            u--;
            a[u] = v; // update
            int blno = u/blsize;
            // abb esa ho sakta hai jo update hua wahi min tha pure block ka 
            // so hamn ye blocks[blno] = min(blocks[blno],a[u]);
            // to pura loop chalayege
            int start = blno*blsize;
            int end = (blno+1)*blsize;
            // ek bahut choti but imp galti
            blocks[blno] = INT_MAX;
            for(int i = start ; i< end; i++){
                blocks[i/blsize] = min(blocks[i/blsize],a[i]);
            }
        }
        else{ // agar retrival query hai to
            u--;
            v--;
            int blockl = u/blsize;
            int block2 = v/blsize;
            if(blockl == block2){
                for(int i=u;i<=v;i++){
                    ret = min(ret, a[i]);
            }
                ans.push_back(ret);
            }
            else{
            // matlab overlapping blocks hai yaha par
                int b1end = (blockl+1)*blsize - 1;
                for(int i=u ; i<= b1end ; i++){
                    ret = min(ret, a[i]);
                }
            // middle part (is part ke answer ke liye precomputation jo kiya tha wo use karenge yaha par)
                for(int i=blockl+1; i<= block2-1;i++){
                // yaha par ye dhyan rakhna hai ki we are iterating in blocks not in array
                    ret = min(ret,blocks[i]);
                }
            // final left out right part
                int blockrend = (block2)*blsize;
                for(int i=blockrend; i<=v;i++){
                    ret = min(ret, a[i]);
                }
                ans.push_back(ret);
            }
        }
    }
    for(int x : ans){
        cout << x << endl;
    }
    return 0;
}