class Solution {
public:
    bool is_valid(int i,int j,int n,int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        int n=grid.size(),m=grid[0].size();
        int mn=1e9;
        vector<vector<int>>g(n,vector<int>(m,1e9));
        while(q.size()){
            auto dep=q.top().first;
            auto x=q.top().second.first;
            auto y=q.top().second.second;
            q.pop();
        
            if(x==n-1&&y==m-1){
                mn=min(mn,dep);
                continue;
            }
            if(g[x][y]<=dep)continue;
            g[x][y]=dep;
            if(is_valid(x+1,y,n,m)&&g[x+1][y]>dep+grid[x+1][y]){
                q.push({dep+grid[x+1][y],{x+1,y}});
            }
            if(is_valid(x-1,y,n,m)&&g[x-1][y]>dep+grid[x-1][y]){
                q.push({dep+grid[x-1][y],{x-1,y}});
            }
            if(is_valid(x,y+1,n,m)&&g[x][y+1]>dep+grid[x][y+1]){
                q.push({dep+grid[x][y+1],{x,y+1}});
            }
            if(is_valid(x,y-1,n,m)&&g[x][y-1]>dep+grid[x][y-1]){
                q.push({dep+grid[x][y-1],{x,y-1}});
            }
            
        }
        return mn;
    }

};