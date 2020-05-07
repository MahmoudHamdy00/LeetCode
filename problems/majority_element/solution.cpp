class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=(int)nums.size();
        for(int i:nums)mp[i]++;
        for(auto it:mp)if(it.second>n/2)return it.first;
        return -1;
    }
};