class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        
        int n=favoriteCompanies.size();
        map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<favoriteCompanies[i].size();j++){
                mp[favoriteCompanies[i][j]].push_back(i);
            }
        }
        vector<int>v;
        
        for(int i=0;i<n;i++){
            unordered_map<int,int>tmp;
            int ans=0;
            for(int j=0;j<favoriteCompanies[i].size();j++){
                for(auto it:mp[favoriteCompanies[i][j]])tmp[it]++;
            }
            int cnt=0;
            for(auto it:tmp){
                if(it.second==favoriteCompanies[i].size())cnt++;
            }
            if(cnt<=1)v.push_back(i);
        }
        return v;
    }
};