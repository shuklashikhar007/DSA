// Given N cards arranged in a row, each card has an associated score denoted by the cardScore array. Choose exactly k cards. In each step, a card can be chosen either from the beginning or the end of the row. The score is the sum of the scores of the chosen cards.
// 
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
        int maxscore(vector<int>& cardpoints, int k){
            int n = cardpoints.size();
            // sabse pehle we will find the intial sum by picking first k cards from the front side 
            int total = 0;
            for(int i=0;i<k;i++){
                total += cardpoints[i];
            }
            int maxpoints = total;
            // ye hamare reference ke liye starting maxpoints honge
            // agge se ek card subtract karke piche se ek card lelo 
            // uske bad adjust the maxpoints value if it changes

            for(int i = 0; i< k;i++){
                total -= cardpoints[k-1-i]; // remove the front value from the total
                total += cardpoints[n-1-i]; // add a value from the back to the total
                maxpoints = max(maxpoints, total); // update the maxpoints value if it changes 
            }
        return maxpoints;
        }
};
int main(){
    vector<int> cards = {1,2,3,4,5,6,1};
    int k = 3;
    Solution sol;
    cout << sol.maxscore(cards,k) << endl;
    return 0;
}