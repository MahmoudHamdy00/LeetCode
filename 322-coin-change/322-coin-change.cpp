class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>mem(1e4,-1);
        int ret=coinChange(coins,amount,mem);
        return ret==1e9?-1:ret;
    }
    int coinChange(vector<int>& coins, int amount,vector<int>&mem) {
        if(amount==0)return 0;
        if(amount <0)return 1e9;
        int &ret=mem[amount];
        if(~ret)return ret;
        ret=1e9;
        for(int i:coins){
            ret=min(ret,coinChange(coins,amount-i,mem)+1);
        }
        return ret;
    }
};