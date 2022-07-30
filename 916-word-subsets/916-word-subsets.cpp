class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int mp[26]={0};
        for(string &s:words2){
            int cur[26]={0};
            for(char &ch:s)
                ++cur[ch-'a'];
            for(int i=0;i<26;++i){
                mp[i]=max(cur[i],mp[i]);            
            }
        }
        vector<string>v;
        set<string>st;
        for(string &s:words1){
            if(st.count(s))continue;
            int cur[26]={0};
            for(char &ch:s)
                ++cur[ch-'a'];
            bool ok=1;
            for(int i=0;i<26;++i){
                if(cur[i]<mp[i]){
                    ok=0;
                    break;
                }              
               
            }
            if(ok){
                v.push_back(s);
                st.insert(s);
            }
        }
        return v;        
    }
};