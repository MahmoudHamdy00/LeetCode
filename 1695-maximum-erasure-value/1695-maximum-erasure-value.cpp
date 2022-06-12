class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int frq[10005]={0};
        int l=0,r=0,mx=0,cur_sum=0;
        while(l<nums.size()){
            while(r<nums.size()&&!frq[nums[r]]){
                cur_sum+=nums[r];
                ++frq[nums[r++]];
            }
            mx=max(mx,cur_sum);
            cur_sum-=nums[l];
            --frq[nums[l++]];
        }
        return mx;
    }
};