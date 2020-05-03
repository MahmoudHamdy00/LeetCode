class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l=0,r=0,ans=0,n=(int)nums.size();
        if(n==0)return 0;
        map<int,int>mp;
        auto mx=mp.end(),mn=mp.begin();
        while(l<n){
            while(r<n){
                mp[nums[r]]++;
                mn=mp.begin();
                mx=mp.end(),mx--;
                r++;
                if(mx->first-mn->first<=limit)ans=max(ans,r-l);
                else break;
            }
            bool ok=1;
            int mnNum=mp.begin()->first;
            int mxNum=(--mp.end())->first;
            while(l<n&&mp.find(mnNum)!=mp.end()&&mp.find(mxNum)!=mp.end()){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
        }
        return ans;
    }
};