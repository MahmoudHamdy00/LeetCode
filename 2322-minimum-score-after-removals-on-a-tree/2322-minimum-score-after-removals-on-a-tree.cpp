class Solution {
    int dp[1005];
    vector<int>adj[1005];
    int ans=1e9;
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<nums.size();++i)dp[i]=nums[i];
        dfs(0,-1);
        int n=nums.size();
        for(int i=1;i<n;++i){
            dfs2(0,-1,i,0);
        }
        return ans;
    }
    int dfs2(int node,int par,int n,bool ok){
        ok|=node==n;
        int ret=node==n;
        for(int nxt:adj[node]){
            if(par==nxt)continue;
            ret|=dfs2(nxt,node,n,ok);
        }
        if(!ret&&node!=0&&node!=n){
            int x1=dp[0]^dp[n]^dp[node];
            int x2=dp[n];
            int x3=dp[node];
            if(ok)
                x1^=dp[node],x2^=dp[node];
            ans=min(ans,max({x1,x2,x3})-min({x1,x2,x3}));
        }
        return ret;
    }
    int dfs(int node,int par){
        for(int nxt:adj[node]){
            if(par==nxt)continue;
            dp[node]^=dfs(nxt,node);
        }
        return dp[node];
    }
};