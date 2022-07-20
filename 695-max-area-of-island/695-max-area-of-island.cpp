class Solution {
    bool mem[51][51];
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                int cnt=0;
                solve(i,j,grid,cnt);
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
    void solve(int i,int j,vector<vector<int>>& grid,int &cnt){
        if(i<0||i==grid.size()||j<0||j==grid[i].size()||!grid[i][j]){
            return;
        }   
        if(mem[i][j])return;
        mem[i][j]=1;
        ++cnt;
        solve(i+1,j,grid,cnt);
        solve(i-1,j,grid,cnt);
        solve(i,j+1,grid,cnt);
        solve(i,j-1,grid,cnt);
    }
};