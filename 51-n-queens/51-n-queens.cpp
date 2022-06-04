class Solution {
    vector<vector<string>>ret;
    vector<string>tmp;
    vector<int>col,dig1,dig2;
    int n;
public:
    vector<vector<string>> solveNQueens(int n) {
        col=dig1=vector<int>(3*n);
        dig2=vector<int>(3*n+1);
        tmp=vector<string>(n,string(n,'.'));
        this->n=n;
        solveNQueens2(0);
        return ret;
    }
     void solveNQueens2(int i) {
        if(i==n){
            ret.push_back(tmp);
        }
        for(int j=0;j<n;++j){
            if(!col[j]&&!dig1[i+j]&&!dig2[i-j+n]){
                col[j]=dig1[i+j]=dig2[i-j+n]=1;
                tmp[i][j]='Q';
                solveNQueens2(i+1);
                tmp[i][j]='.';
                col[j]=dig1[i+j]=dig2[i-j+n]=0; 
            }
        }
    }
};