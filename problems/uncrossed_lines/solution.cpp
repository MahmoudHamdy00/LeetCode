class Solution {
    int n,m;
    vector<int>a,b;
    vector<vector<int>>mem;
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        a=A,b=B,n=A.size(),m=B.size();
        mem=vector<vector<int>>(n,vector<int>(m,-1));
        return solve(0,0);
    }
    int solve(int i,int j){
        if(i>=n||j>=m)return 0;
        int &ret=mem[i][j];
        if(~ret)return ret;
        ret=0;
        if(a[i]==b[j])ret=1+solve(i+1,j+1);
        ret=max(ret,solve(i+1,j));
        ret=max(ret,solve(i,j+1));
        return ret;
    }
};