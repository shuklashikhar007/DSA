#include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A){
    int n = A.size();
    // ek array which will store the answer seprately 
    vector<int> ans(n,0); // of n size having all elements 0
    int posindex = 0;
    int negIndex = 1;
    // positive wale 0 se start hote hai aur negative wale 1 se 
    for(int i=0;i<n;i++){
        // odd index pe negative store karke 2 se badha do 
        if(A[i] < 0){
            ans[negIndex] = A[i];
            negIndex += 2;
        }
        else{
            // even index pe positive value store karke 2 se badha do
            ans[posindex] = A[i];
            posindex += 2;
        }

    }
    return ans;
    
}

int main() {
    
  // Array Initialisation.
  
  vector<int> A = {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}