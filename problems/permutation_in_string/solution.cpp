class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>ret;
        int szS1=s1.size(),szS2=s2.size();
        if(szS1>szS2)return 0;
        
        map<char,int>mp,mp2;
        for(char ch:s1)mp[ch]++;
        
        for(int i=0;i<szS1;i++)mp2[s2[i]]++;
        int l=0,r=szS1;
        while(r<szS2){
            if(mp2==mp)return 1;
            mp2[s2[r]]++;
            mp2[s2[l]]--;
            if(mp2[s2[l]]==0)mp2.erase(s2[l]);
            l++,r++;
           
        }
        if(mp2==mp)return 1;
        return 0;
    }
};