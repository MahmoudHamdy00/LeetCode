class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int>mp,org;
        for(string&cur:words)++mp[cur];
        org=mp;
        int len=words[0].size();
        int substringLen=len*words.size();
        vector<int>ret;
        for(int i=0;i+substringLen<=s.size();++i){
            mp=org;
            bool ok=1;
            for(int j=i;j<i+substringLen;j+=len){
                string cur="";
                for(int k=j;k<j+len;++k){
                    cur+=s[k];
                }
                if(mp.find(cur)==mp.end()){
                    break;
                }
                if(--mp[cur]==0){
                    mp.erase(cur);
                }
            }
            if(mp.empty())ret.push_back(i);
        }
        return ret;
    }
};