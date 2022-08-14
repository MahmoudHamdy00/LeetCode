class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merged;
        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);
        for(auto &it:intervals){
            if(merged.back()[1]>=it[0]){
                merged.back()[1]=max(it[1],merged.back()[1]);
            }
            else merged.push_back(it);
        }
        return merged;
    }
};