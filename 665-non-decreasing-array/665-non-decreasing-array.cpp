class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(modified)return 0;
                modified=1;
                if(i-1>=0){
                    if(nums[i+1]>=nums[i-1])nums[i]=nums[i-1];
                    else nums[i+1]=nums[i];
                }
            }
        }
        return true;
    }
};