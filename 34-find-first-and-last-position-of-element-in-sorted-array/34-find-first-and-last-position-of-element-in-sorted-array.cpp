class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ret(2,-1);
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]!=target)continue;
            if(!~ret[0])
                ret[0]=i;
            ret[1]=i;
        }
        return ret;
    }
};