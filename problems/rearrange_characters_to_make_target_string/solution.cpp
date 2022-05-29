class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int frq[26]={0};
        int frq2[26]={0};
        for(char ch:s)++frq[ch-'a'];
        int mn=1e9;     
        for(char ch:target)++frq2[ch-'a'];
        for(int i=0;i<26;++i){
            if(frq2[i])
            mn=min(mn,frq[i]/frq2[i]);
        }
        return mn;
    }
};