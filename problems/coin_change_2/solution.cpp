class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0)return 1;
        if(coins.size()==0)return 0;
        
        sort(coins.begin(),coins.end());
        
        vector<int>dp(amount+1);
            dp.front() = 1;
        for(int j=0;j<coins.size();j++){
              for(int i=coins[j];i<=amount;i++){
                dp[i]+=dp[i-coins[j]];
            }
        }
      
        return dp[amount];
    }

};