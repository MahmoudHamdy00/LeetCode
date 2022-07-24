class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>>cols;
        int n=grid.size();
        int m=grid[0].size();
        for(int j=0;j<m;++j){
            cols.push_back(vector<int>());
            for(int i=0;i<n;++i){
                cols.back().push_back(grid[i][j]);
            }
        }
        int cnt=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)
                cnt+=grid[i]==cols[j];
        }
        return cnt;
    }
};