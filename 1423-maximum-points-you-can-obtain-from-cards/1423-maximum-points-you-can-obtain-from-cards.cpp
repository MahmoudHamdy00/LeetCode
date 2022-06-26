class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>v= cardPoints;
        int n=v.size();
        for(int i=1;i<n;i++)v[i]+=v[i-1];
        for(int i=n-2;i>=0;i--)cardPoints[i]+=cardPoints[i+1];
        int mx=0;
        cardPoints.push_back(0);
        for(int i=0;i<k;i++){
            int cur=v[i]+cardPoints[n-k+i+1];
            mx=max(mx,cur);
        }
        mx=max(mx,v[k-1]);
        mx=max(mx,cardPoints[n-k]);
        return mx;
    }
};