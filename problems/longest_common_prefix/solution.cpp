class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz=INT_MAX;
        for(string s:strs)sz=min(sz,(int)s.size());
        string ret="";
        for(int i=0;i<sz&&sz!=INT_MAX;i++){
            bool ok=1;
            for(string s:strs)ok&=strs[0][i]==s[i];
            if(ok)ret+=strs[0][i];
            else return ret;
        }
        return ret;
    }
};