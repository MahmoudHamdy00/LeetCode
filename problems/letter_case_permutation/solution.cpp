class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string>ret;
        set<string>ret2;
        int n=S.size();
        for(int i=0;i<(1<<n);i++){
            string s=S;
            bool ok=0;
            for(int j=0;j<n;j++){
                if(isalpha(s[j])){
                    ok=1;
                    if(i&(1<<j)){
                        s[j]=isupper(s[j])?s[j]+=32:s[j]-=32;
                    }
                }
            }
                ret2.insert(s);
        }
        for(auto it:ret2)ret.push_back(it);

        return ret;
    }
};