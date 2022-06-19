class Solution {
    long long arr[201][201];
    long long mem[201][201];
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        for(auto it:prices)arr[it[0]][it[1]]=it[2];
        memset(mem,-1,sizeof mem);
        return solve(m,n);
    }
    long long solve(int m, int n) {
        long long &ret=mem[m][n];
        if(~ret)return ret;
        ret=arr[m][n];
        for(int i=1;i<m;++i){
            ret=max(ret,solve(i,n)+solve(m-i,n));
        }
        for(int i=1;i<n;++i){
            ret=max(ret,solve(m,i)+solve(m,n-i));
        }
        return ret;
    }
};