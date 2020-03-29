class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums){
            if(mp.find(i)!=mp.end())return i;
            mp[i]++;
        }
        return 0;
    }
};