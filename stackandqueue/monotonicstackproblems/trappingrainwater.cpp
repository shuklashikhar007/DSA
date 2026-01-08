#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int trap(vector<int> &hei){
        int n = hei.size();
        int left = 0;
        int right = n-1;
        int maxleft = 0, maxright = 0;
        int totalwater = 0;
        while (left <= right){
            if(hei[left] <= hei[right]){
                // agar left has less or equal height to right then it will be deciding 
                if(hei[left] >= maxleft){
                    maxleft = hei[left];
                }
                else{
                    totalwater += maxleft - hei[left];
                }
                left++;
            }
            else{ // agar height of right bar is less than left bar to abb ye decide karega
                if(hei[right] >= maxright){
                    maxright = hei[right];
                }
                else{
                    totalwater += maxright - hei[right];
                }
                right--;
            }
        }
        return totalwater;
    }
};
int main(){

    return 0;
}