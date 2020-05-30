class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,vector<int>>>v;
        for(int i=0;i<points.size();i++){
            v.push_back({points[i][0]*points[i][0]+points[i][1]*points[i][1],points[i]});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ret;
        for(int i=0;i<K;i++){
            ret.push_back(v[i].second);
        }
        return ret;
    }
};