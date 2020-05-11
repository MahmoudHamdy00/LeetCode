class Solution {
public:
    bool isPalindrome(string s) {
        string def="";
        for(char ch:s)if(isalpha(ch)||isdigit(ch))def+=tolower(ch);
        string rev=def;
        reverse(rev.begin(),rev.end());
        return rev==def;
    }
};