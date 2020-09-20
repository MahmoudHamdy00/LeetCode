class Solution {
private:
    int x,y,n,m;
    vector<vector<int>>g;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ok=0;
        n=(int)grid.size();
        if(!n)return 0;
        m=(int)grid[0].size();
        g=grid;
        int ii,jj;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
            if(grid[i][j]==1)
                ii=i,jj=j;
            
            else if(grid[i][j]==2)
                x=i,y=j;
            if(grid[i][j]>=0)ok++;
            }
     
        return solve(ii,jj,ok);

    }
    bool valid(int i,int j){
        return i<n&&i>=0&&j<m&&j>=0&&g[i][j]>=0;
    }
    int solve(int i,int j,int rem){
        if(!valid(i,j))return 0;
        if(g[i][j]==2&&rem==1){
            return 1;
        }
        int tmp=g[i][j];
        g[i][j]=-5;
       
        int ans=solve(i+1,j,rem-1);
        ans+=solve(i-1,j,rem-1);
        ans+=solve(i,j+1,rem-1);
        ans+=solve(i,j-1,rem-1);
        g[i][j]=tmp;
        return ans;
        
    }
};