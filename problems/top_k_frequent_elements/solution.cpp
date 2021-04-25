class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int &i:nums){
            mp[i]++;
        }
        vector<pair<int,int>>v;
        for(auto &it:mp)v.push_back({it.second,it.first});
        sort(v.rbegin(),v.rend());
        vector<int>ret;
        for(int i=0;i<k;i++)ret.push_back(v[i].second);
        return ret;
    }
};