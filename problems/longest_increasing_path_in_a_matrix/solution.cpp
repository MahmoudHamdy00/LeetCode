class Solution {
    vector<int> dx={1,0,-1,0};
    vector<int>  dy={0,1,0,-1};
    int mem[200][200];
    int n,m;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(mem,-1,sizeof mem);
        n=matrix.size();
        m=matrix[0].size();
        int mx=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                mx=max(mx,longestIncreasingPath(i,j,matrix));
            }
        } 
        return mx+1;
    }
    int longestIncreasingPath(int i,int j,vector<vector<int>>& v) {
        int &ret=mem[i][j];
        if(~ret)return ret;
        ret=0;
        for(int k=0;k<4;++k){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=n||y>=m||x<0||y<0||v[x][y]<=v[i][j])continue;
            ret=max(ret,longestIncreasingPath(x,y,v)+1);
        }
        return ret;

    }
};