class Solution {
    int dp[1001][1001][3];
public:
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        if(nums.size()==1)return 1;
        return solve(0,0,0,nums);
    }
    int solve(int i,int lst,int state,vector<int>& nums) {
        if(i>=nums.size())return 0;
       // cout<<i<<" "<<lst<<" "<<state<<endl;
        int &ret=dp[i][lst][state];
        if(~ret)return ret;
        ret=solve(i+1,lst,state,nums);
        for(int j=i;j<nums.size();++j){
            if(state!=1)
            {
                if(nums[i]>lst||state==0)
                    ret=max(ret,solve(i+1,nums[i],1,nums)+1);
            }
             if(state!=2) {
                if(nums[i]<lst||state==0)
                    ret=max(ret,solve(i+1,nums[i],2,nums)+1);

            }
        }
        return ret;
    }
};