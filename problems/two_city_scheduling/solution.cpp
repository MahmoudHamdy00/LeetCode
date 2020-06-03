class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[&](vector<int>a,vector<int>b)->bool{
            return a[0]-a[1]<b[0]-b[1];
        });
        int n=costs.size()>>1,ans=0;
        for(auto it:costs){
            if(n-->0)ans+=it[0];
            else ans+=it[1];
        }
        return ans;
    }
};