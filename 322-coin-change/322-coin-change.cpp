class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>mem(amount+1,1e9);
        mem[0]=0;
        for(int am=0;am<=amount;++am){
            int&ret=mem[am];
            for(int i:coins){
                if(am-i>=0)
                    ret=min(ret,mem[am-i]+1);
            }
        }
        return mem[amount]==1e9?-1:mem[amount];
    }
};