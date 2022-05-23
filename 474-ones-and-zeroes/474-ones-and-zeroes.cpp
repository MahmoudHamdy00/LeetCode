class Solution {
    int mem[105][105][605];
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(mem,-1,sizeof mem);
        int mm=0,nn=0;
        vector<vector<int>>v;
        for(auto it:strs){
            int ones=0,zeros=0;
            for(char ch:it){
                ch=='0'?++zeros:++ones;
            }
            v.push_back({zeros,ones});
            mm+=zeros;nn+=ones;
        }
        if(mm<=m&&nn<=n)return v.size();
        return solve(v,m,n,0);
    }
    int solve(vector<vector<int>>&v,int m,int n,int i){
        if(n<0||m<0)return -1e9;
        if(i==v.size())return 0;
        int &ret=mem[m][n][i];
        if(~ret)return ret;
        ret=solve(v,m,n,i+1);  
        ret=max(ret,solve(v,m-v[i][0],n-v[i][1],i+1)+1);
        return ret;

    }
};