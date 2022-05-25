class Solution {
    vector<int>mem;
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> lis;
        for (auto it : envelopes) {
            int left = lower_bound(lis.begin(), lis.end(),  it[1]) - lis.begin();
            if (left == lis.size()) lis.push_back( it[1]);
            lis[left] =  it[1];
        }
        return lis.size();
    }
};