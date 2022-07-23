class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0,cur=0;
        for(int i=0;i<n;++i){
            if(nums[i]!=0){
                ans+=cur*(cur+1)/2;
                cur=0;
                continue;
            }
            
            ++cur;
        }
        ans+=cur*(cur+1)/2;
        return ans;
    }
};