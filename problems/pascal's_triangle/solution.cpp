class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pas;
                
        for(int i=0;i<numRows;i++){
            vector<int>v;
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    v.push_back(1);
                    continue;
                }
                int cur=pas[i-1][j]+pas[i-1][j-1];
                v.push_back(cur);
            }
            pas.push_back(v);

        }
        return pas;
    }
};