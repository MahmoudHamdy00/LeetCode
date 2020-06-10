class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size())return 0;
        if(s==t)return 1;
        int i=0;
        for(char ch:t){
            if(s[i]==ch)i++;
            if(i==s.size())return 1;
        }
        return 0;
    }
};