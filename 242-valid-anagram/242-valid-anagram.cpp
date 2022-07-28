class Solution {
public:
    bool isAnagram(string s, string t) {
        int frq1[26]={0},frq2[26]={0};
        for(char ch:s)frq1[ch-'a']++;
        for(char ch:t)frq2[ch-'a']++;
        for(int i=0;i<26;i++)if(frq1[i]!=frq2[i])return 0;
        return 1;
    }
};