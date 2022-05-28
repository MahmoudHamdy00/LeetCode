class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        vector<int>out(n);
        for(auto it:roads)
            out[it[0]]++,
            out[it[1]]++;
        
        vector<pair<int,int>>v;
        for(int i=0;i<n;++i){
            v.push_back({out[i],i});
        }
        sort(v.begin(),v.end());
        
        map<int,int>mp;
        for(int i=0;i<n;++i)
            mp[v[i].second]=i+1;
        
        long long ret=0;
        for(auto it:roads)
            ret+=1LL*mp[it[0]]+mp[it[1]];

        return ret;
    }
};