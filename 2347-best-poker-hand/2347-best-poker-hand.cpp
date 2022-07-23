class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char ,int>mp;
        for(char ch:suits)++mp[ch];
        for(auto it:mp)if(it.second==5)return "Flush";
        
        map<int ,int>mp3;
        for(int ch:ranks)++mp3[ch];
        for(auto it:mp3)if(it.second>=3)return "Three of a Kind";
        for(auto it:mp3)if(it.second>=2)return "Pair";
        return "High Card";
        
        
    }
};