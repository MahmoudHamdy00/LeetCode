class Solution {
public:
    string frequencySort(string s) {
        map<char,int>frq;
        for(char ch:s)frq[ch]++;
        vector<pair<int,char>>v;
        for(auto it:frq){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        string ret="";
        for(int i=0;i<v.size();i++){
            ret+=string(v[i].first,v[i].second);
        }
        return ret;
    }
};