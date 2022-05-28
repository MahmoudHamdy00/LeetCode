class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long curSum=0,sum=0;
        for(int i:nums){
            curSum+=i;
        }
        int n=nums.size();
        sum=n*(n+1)/2;
        return sum-curSum;
    }
};