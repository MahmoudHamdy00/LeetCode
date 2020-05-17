class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ret;
        int szS=s.size(),szP=p.size();
        if(szS<szP)return ret;
        
        map<char,int>mp,mp2;
        for(char ch:p)mp[ch]++;
        
        for(int i=0;i<szP;i++)mp2[s[i]]++;
        int l=0,r=szP;
        while(r<szS){
            if(mp2==mp)ret.push_back(l);
            mp2[s[r]]++;
            mp2[s[l]]--;
            if(mp2[s[l]]==0)mp2.erase(s[l]);
            l++,r++;
        }
        if(mp2==mp)ret.push_back(l);
        return ret;
    }
};