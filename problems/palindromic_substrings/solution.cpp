class Solution {
public:
    int countSubstrings(string s) {
        int ret=0;
        for(int i=0;i<s.size();++i){
            int l=i,r=i;
            while(l>=0&&r<s.size()&&s[l--]==s[r++]){
                ++ret;
            }
        }
        for(int i=0;i<s.size();++i){
            int l=i,r=i+1;
            while(l>=0&&r<s.size()&&s[l--]==s[r++]){
                ++ret;
            }
        }
        return ret;
    }
};