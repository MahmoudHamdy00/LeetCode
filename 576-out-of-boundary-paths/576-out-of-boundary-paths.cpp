class Solution {
    int mem[51][51][51],n,m,mod=1e9+7;
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        memset(mem,-1,sizeof mem);
        this->n=n,this->m=m;
        return solve(startRow,startColumn,maxMove);
    }
    int solve(int i,int j,int rem){
        if(rem<0)return 0;
        if(i<0||i>=n||j<0||j>=m){
            return 1;
        }
        int &ret=mem[i][j][rem];
        if(~ret)return ret;
        ret=solve(i+1,j,rem-1);
        ret%=mod;
        ret+=solve(i-1,j,rem-1);
        ret%=mod;
        ret+=solve(i,j+1,rem-1);
        ret%=mod;
        ret+=solve(i,j-1,rem-1);
        ret%=mod;
        return ret;
        
    }
};