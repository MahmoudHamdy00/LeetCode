class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX,mx=0;;
        for(int i=0;i<(int)prices.size();i++){
            mn=min(mn,prices[i]);
            mx=max(mx,prices[i]-mn);
        }
        return mx;
    }
};