class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=(int)nums.size();
        int mx=0,cur=0;;
        for(int i=0;i<n;i++)mx=max(mx,(int)nums[i].size());
        vector<vector<int>>v(mx+n+10);
        vector<int >ret;
        for(int i=0;i<n;i++){
            for(int j=0;j<(int)nums[i].size();j++)
                v[j+cur].push_back(nums[i][j]);
            cur++;
        }
        for(int i=0;i<mx+n+10;i++){
            for(int j=(int)v[i].size()-1;j>=0;j--)
                ret.push_back(v[i][j]);
        }
        return ret;
    }
};