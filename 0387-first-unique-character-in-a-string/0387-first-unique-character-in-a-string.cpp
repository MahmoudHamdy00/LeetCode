class Solution {
public:
    int firstUniqChar(string s) {
        int frq[26]={0};
        for (char ch:s)frq[ch-'a']++;
        int i=0;
        for (char ch:s){if(frq[ch-'a']==1)return i;i++;}

        return -1;
    }
};