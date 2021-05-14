class Solution {
    int mem[1005][1005];
public:
    string longestPalindrome(string s) {
        memset(mem,-1,sizeof mem);
        for(int len=s.size();len>=0;len--){
            for(int i=0;i+len-1<s.size();i++){
                if(isPalindrome(s,i,i+len-1))return s.substr(i,len);
            }
        }
        return 0;
    }
    bool isPalindrome(string &s,int l,int r){
        if(l>r)return 1;
        if(~mem[l][r])return mem[l][r];

        return mem[l][r]=(s[l]==s[r]&&isPalindrome(s,l+1,r-1));
    }
};