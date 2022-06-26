class Solution {
    int mem[10005][4],mod=1e9+7;
public:
    int countHousePlacements(int n) {
        memset(mem,-1,sizeof mem);
        return solve(0,0,n);
    }
    int solve(int i,int prv,int n) {
        if(i==n){
            return 1;
        }
        int &ret=mem[i][prv];
        if(~ret)return ret;
        ret=0;
            ret+=solve(i+1,0,n),
            ret%=mod;
        if((prv&1)==0)
            ret+=solve(i+1,1,n),
            ret%=mod;
        if((prv&2)==0)
            ret+=solve(i+1,2,n),
            ret%=mod;
        if((prv&3)==0)
            ret+=solve(i+1,3,n),
            ret%=mod;
        return ret%=mod;
    }
};