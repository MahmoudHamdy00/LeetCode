class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2505];
        int n=nums.size();
        for(int i=0;i<n;++i)
            dp[i]=1;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(nums[j]>nums[i])
                    dp[j]=max(dp[j],dp[i]+1);
            }
        }
        return *max_element(dp,dp+n);
    }
};