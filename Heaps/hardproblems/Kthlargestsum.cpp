// bahut hi acche level ki maths ka logic lag raha hai is question mai 
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        using ll = long long;
        long long ksum(vector<int>&nums, int k){
            ll possum = 0;
            vector<ll>a;
            for(int x : nums){
                // max possible subseq sum
                if(x>0) possum+=x;
                a.push_back(abs((ll)x));
                // abs value isliye push kar rahe hai 
                // kyoki value -2 lena and +2 remove karna same cheez hai
            }
            sort(a.begin(),a.end());
            int n = a.size();
            if(k==1) return possum; // iska matlab max sum manga hai
            priority_queue<pair<ll,int>, vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
            pq.push({a[0],0});
            for(int j=1;j<k;j++){
                auto[sum,i] = pq.top();
                pq.pop();
                if(i+1<n){
                    pq.push({sum+a[i+1],i+1});
                    pq.push({sum-a[i]+a[i+1],i+1});
                }
                if(j == k-1) return possum-sum;
            }
        }
};
int main(){

    return 0;
}