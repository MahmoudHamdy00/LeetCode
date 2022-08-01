class Solution {
    int mem[100][100];;
public:
    int uniquePaths(int m, int n) {
        memset(mem,-1,sizeof mem);
        return solve(0,0,m,n);
    }
    int solve(int i,int j,int m, int n) {
        if(i==m-1&&j==n-1)return 1;
        if(i==m||j==n)return 0;
        int &ret=mem[i][j];
        if(~ret)return ret;
        ret=0;
        return ret=solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
};