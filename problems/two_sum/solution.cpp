class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
       for(int i=0;i<nums.size();i++){
           if(mp.find(target-nums[i])!=mp.end()){
               int idx=mp[target-nums[i]];
               if(idx!=i)return {i,idx};
           }
       }
        return{0,0};
    }
};