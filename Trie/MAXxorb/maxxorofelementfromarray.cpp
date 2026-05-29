#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // sabse pehle Trie data structure bana lenge
    class Node{
        public:
        Node* nxt[2];
        Node(){
            nxt[0] = nxt[1] = NULL;
        }
        bool has(int bit){
            return nxt[bit] != NULL;
        }
        void put(int bit, Node* node){
            nxt[bit] = node;
        }
        Node* get(int bit){
            return nxt[bit];
        }
    };
    class Trie{
        public:
        Node* root;
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node* node = root;
            // root node ka reference le liya
            for(int i=31; i>=0 ; i--){
                int bit = (num >> i) & 1;// is number ki it bit
                if(!node->has(bit)){ // agar trie mai pehle se path nahi exist karta hai to 
                    node->put(bit, new Node());
                }
                node = node->get(bit); // agar path hai to uspe chale jao
            }
        }

        int maxxor(int num){
            Node* node = root; // root node ka reference le liya yaha pe
            int maxi = 0;
            for(int i=31; i>=0 ; i--){
                int bit = (num >> i) & 1; // number ki ith bit 
                if(node->has(1-bit)){
                    maxi |= 1 << i;
                    node= node->get(1-bit);
                }
                else node = node->get(bit); // agar nahi mili opposite bit to move on the alternate path
            }
            return maxi;
        }
    };
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int q = queries.size();
        vector<pair<int,pair<int,int>>> off;
        // {max, (xi, ind)}
        for(int i=0;i<q;i++){
            off.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(off.begin(),off.end());
        vector<int>ans(q);
        Trie trie;
        int n = nums.size();
        int ind  = 0; // array ko traverse karne ke liye
        for(auto &it : off){
            int mi = it.first;
            int xi = it.second.first;
            int qind = it.second.second;
            while(ind < n && nums[ind] <= mi){ // sare chote elements ko hi trie mai dalo 
                trie.insert(nums[ind]);
                ind++; 
            }
            if(ind == 0){
                ans[qind] = -1;
            }
            else{
                ans[qind] = trie.maxxor(xi);
            }
        }
        return ans;
    }
};
int main(){

    return 0;
}