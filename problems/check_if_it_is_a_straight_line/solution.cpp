class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=(int)coordinates.size();
        bool ok=true;
        for(int i=2;i<n;i++){
          //  x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
             ok&=coordinates[0][0] * (coordinates[1][1]  - coordinates[i][1] ) + coordinates[1][0]  * (coordinates[i][1]  - coordinates[0][1] ) + coordinates[i][0]  * (coordinates[0][1]  - coordinates[1][1] )==0;
        }
        return ok;
    }
};