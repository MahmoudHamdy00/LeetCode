class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(!n)return 0 ;
        int m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==j||j==m-i-1){
                    if(!grid[i][j])return 0;
                }
                else 
                    if(grid[i][j])return 0;
                    
            }
        }
        return 1;
    }
};