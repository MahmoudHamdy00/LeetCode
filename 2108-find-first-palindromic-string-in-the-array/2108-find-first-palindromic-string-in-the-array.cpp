class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            string t=s;
            reverse(t.begin(),t.end());
            if(s==t)return s;
        }
        return "";
    }
};