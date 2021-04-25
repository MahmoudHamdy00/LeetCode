class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(!n)return 0;
        int cnt=1;
        int idx=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])cnt++,nums[++idx]=nums[i];
        }
        return cnt;
    }
};