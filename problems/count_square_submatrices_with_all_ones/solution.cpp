class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        for(int j=1;j<matrix[0].size();j++){
             for(int i=0;i<matrix.size();i++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
    
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
               for (int k=0;i+k<matrix.size()&&j+k<matrix[i].size();k++){
                   int cur=matrix[i+k][j+k];
                   if(i-1>=0)cur-=matrix[i-1][j+k] ;                  
                   if(j-1>=0)cur-=matrix[i+k][j-1];
                   if(j-1>=0&&i-1>=0)cur+=matrix[i-1][j-1];
                   int need=max(i+k-i+1,j+k-j+1);
                   need*=need;
                   if(need==cur)cnt++;
               }
            }
        }
        return cnt;
    }
};