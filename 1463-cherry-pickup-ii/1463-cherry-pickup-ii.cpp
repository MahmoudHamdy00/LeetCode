class Solution {
    int mem[71][71][71];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(mem,-1,sizeof mem);
        return cherryPickup(0,0,grid[0].size()-1,grid);
    }
    int cherryPickup(int i,int j1,int j2,vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(!is_valid(i,j1,n,m)||!is_valid(i,j2,n,m))return 0;
        int &ret=mem[i][j1][j2];
        if(~ret)return ret;
        int cur=grid[i][j1];
        if(j1!=j2)cur+=grid[i][j2];
        if(i==grid.size()-1)return cur;
        ret=cur;
        for(int d1=-1;d1<=1;++d1){
            for(int d2=-1;d2<=1;++d2){
                ret=max(ret,cur+cherryPickup(i+1,j1+d1,j2+d2,grid));
            }
        }
        return ret;
    }
    bool is_valid(int i,int j,int n,int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }
};