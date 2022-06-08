class Solution {
public:
    int removePalindromeSub(string s) {
        int l=0,r=s.size()-1;
        while(l<r&&s[l]==s[r])++l,r--;
        if(l>=r)return 1;
        return 2;
    }
};