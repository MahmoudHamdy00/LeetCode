class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        map<char,int>mp;
        for(char ch:s)++mp[ch];
        int cnt=0;
        bool odd=0;
        for(auto it:mp){
            cnt+=it.second>>1;
            odd|=it.second&1;
        }
        return cnt*2+(odd==1);
    }
};