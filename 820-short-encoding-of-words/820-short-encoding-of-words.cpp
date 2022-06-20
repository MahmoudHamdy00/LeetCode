class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if(words.size()==0)return 0;
        int cnt=0;
        unordered_set<string>st;
        for(string& s:words)
            st.insert(s);
        for(string& s:words)
            for(int i=1;i<s.size();++i){
                st.erase(s.substr(i));
            }
        for(auto s:st)
            cnt+=s.size()+1;
        
        return cnt;
    }
};