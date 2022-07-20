class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>indices(s.size(),vector<int>(26,-1));
        vector<int>tmp(26,s.size());
        for(int i=s.size()-1;i>=0;--i){
            indices[i]=tmp;
            tmp[s[i]-'a']=i;
        }
        int cnt=0;
        for(string cur:words){
            int idx=tmp[cur[0]-'a'];
            bool ok=1;
            if(idx==s.size())ok=0;
            for(int i=1;i<cur.size()&&ok;++i){
                if((idx=indices[idx][cur[i]-'a'])==s.size())ok=0;
            }
            cnt+=ok;
        }
        return cnt;
    }
   
};