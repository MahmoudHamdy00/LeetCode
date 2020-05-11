class Solution {
public:
    int mem[10000000],N;
    
    int climbStairs(int n) {
        N=n;
        memset(mem, -1, sizeof mem);
        return solve();
    }
    int solve(int cur=0){
        if(cur>N)return 0;
        if(cur==N)return 1;
        int &ret=mem[cur];
        if(~ret)return ret;
        ret=0;
        ret+=solve(++cur);
        ret+=solve(++cur);
        return ret;
    }
};