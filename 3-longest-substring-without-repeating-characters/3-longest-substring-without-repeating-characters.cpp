class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=s.size(),md,ans=0;
        while(l<=r){
            md=(l+r)>>1;
            if(check(md,s)){
                l=md+1;
                ans=md;
            }
            else r=md-1;
        }
        return ans;
    }
    bool check(int len,string &s){
        map<char,int>mp;
        for(int i=0;i<len;i++){
            mp[s[i]]++;
        }
        if(mp.size()==len)return 1;
        for(int i=len;i<s.size();i++){
            if(--mp[s[i-len]]==0)mp.erase(s[i-len]);
            mp[s[i]]++;
            if(mp.size()==len)return 1;
        }
        return 0;
    }
};