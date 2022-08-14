class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>spiral;
        int x_st=0,y_st=0;
        int x_ed=matrix.size()-1,y_ed=matrix[0].size()-1;
        while(true){
            for(int j=y_st;j<=y_ed;++j){
                if(matrix[x_st][j]==200)continue;
                spiral.push_back(matrix[x_st][j]);
                matrix[x_st][j]=200;
            }
            for(int i=x_st+1;i<=x_ed;++i){
                if(matrix[i][y_ed]==200)continue;
                spiral.push_back(matrix[i][y_ed]);
                matrix[i][y_ed]=200;
                
            }
            for(int j=y_ed-1;j>=y_st;--j){
                if(matrix[x_ed][j]==200)continue;
                spiral.push_back(matrix[x_ed][j]);
                matrix[x_ed][j]=200;
            }
            for(int i=x_ed-1;i>x_st;--i){
                if(matrix[i][y_st]==200)continue;
                spiral.push_back(matrix[i][y_st]);
                matrix[i][y_st]=200;
            }
            ++x_st,++y_st;
            --x_ed,--y_ed;
            if(x_st>x_ed||y_st>y_ed)break;
        }
        return spiral;
    }
};