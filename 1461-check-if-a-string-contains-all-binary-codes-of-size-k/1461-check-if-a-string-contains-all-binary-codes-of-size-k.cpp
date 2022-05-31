class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return 0;
        for(char&ch:s)ch-='0';
        set<int>st;
        int cur=0;
        for(int i=0;i<k;++i){
            cur<<=1;
            cur&=(1<<k)-1;
            cur|=s[i];
        }
        st.insert(cur);
        for(int i=k;i<s.size();++i){
            cur<<=1;
            cur&=(1<<k)-1;
            cur|=s[i];
            st.insert(cur);
            if(st.size()==(1<<k))return 1;
        }
        return 0;
    }
};