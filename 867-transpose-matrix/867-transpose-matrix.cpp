class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int N=n,M=m;
        if(n>m){
            for(int i=0;i<n;++i){
                    matrix[i].resize(n);
                
            }
        }
        else{
            for(int i=n;i<m;++i){
                 matrix.push_back(vector<int>(m));
            }
        }
        n=max(n,m);
        for(int i=0;i<n;++i){
            for(int j =0;j<=i;++j){
                swap(matrix[i][j],matrix[j][i]);
            }

        }
        if(N>M){
            for(int i=M;i<N;++i){
                matrix.pop_back();
            }
        }
        else{
            for(int i=0;i<n;++i){
                matrix[i].resize(N);
            }
        }
        return matrix;
    }
};