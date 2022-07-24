class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int>st;
        vector<int>v;
        for(int i:nums){
            if(st.count(i))continue;
            st.insert(i);
            int cnt=0;
            while(i){
                cnt++;
                i&=i-1;
            }
            v.push_back(cnt);
        }
        sort(v.begin(),v.end());
        long long ans=0;        
        for(int i=0;i<v.size();++i){
            int idx=lower_bound(v.begin(),v.end(),k-v[i])-v.begin();
            ans+=v.size()-idx;
        }
        return ans;
    }
};