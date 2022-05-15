class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        --k;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
        vector<int>vis(n,1e9);
        q.push({0,k});
        int mx=0;
        vis[k]=0;
        while(!q.empty()){
            auto cur=q.top();q.pop();
            if(vis[cur.second]<cur.first)continue;
            vis[cur.second]=cur.first;
            for(auto& nxt:adj[cur.second]){
                if(vis[nxt.first]>=vis[cur.second]+nxt.second){
                    nxt.second=vis[cur.second]+nxt.second;
                    q.push({nxt.second,nxt.first});
                }
            }
        }
        for(int i:vis)
            mx=max(mx,i);
        return mx==1e9?-1:mx;

    }
};