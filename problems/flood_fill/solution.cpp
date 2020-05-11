class Solution {
private:
    int n,m,col,cur;
    vector<vector<int>>grid;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=(int)image.size();
        if(!n)return grid;
        m=(int)image[0].size();
        col=newColor;

        grid=image;
        cur=grid[sr][sc];
        if(cur!=col)
        replace(sr,sc);
        return grid;
    }
    bool valid(int i,int j){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    void replace(int i,int j){
        if(!valid(i,j)||grid[i][j]!=cur)return;
        
        grid[i][j]=col;
        replace(i+1,j);
        replace(i-1,j);
        replace(i,j+1);
        replace(i,j-1);

    }
};