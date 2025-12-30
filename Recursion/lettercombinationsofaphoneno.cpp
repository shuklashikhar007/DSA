/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> ans = {""};  
        for (char d : digits) {
            int digit = d - '0';
            vector<string> temp;

            for (string &prefix : ans) {
                for (char ch : mapping[digit]) {
                    temp.push_back(prefix + ch);
                }
            }
            ans = temp; 
        }
        return ans;
    }
};






*/