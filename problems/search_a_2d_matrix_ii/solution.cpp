class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto&it:matrix){
            if(it.front()>target)continue;
            if(binary_search(it.begin(),it.end(),target))return true;
        }
        return false;
    }
};