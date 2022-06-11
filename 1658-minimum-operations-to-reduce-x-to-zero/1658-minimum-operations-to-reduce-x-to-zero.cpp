class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>prefix_sum(n);
        for(int i=0;i<n;++i){
            prefix_sum[i]=nums[i];
            if(i)prefix_sum[i]+=prefix_sum[i-1];
        }
        int mn=1e9;
        int cur=lower_bound(prefix_sum.begin(),prefix_sum.end(),x)-prefix_sum.begin();
        if(cur!=n&&prefix_sum[cur]==x)
                mn=min(mn,cur+1);
        for(int i=n-1;x>0&&i>=0;--i){
            x-=nums[i];
            if(x==0){
                mn=min(mn,n-i);
                break;
            }
            int cur=lower_bound(prefix_sum.begin(),prefix_sum.end(),x)-prefix_sum.begin();
            if(cur<i&&prefix_sum[cur]==x)
                mn=min(mn,cur+1+n-i);
        }
        return (mn==1e9?-1:mn);
    }
};