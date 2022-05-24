class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>v(s.size(),0);
        stack<int>st;
        int ret=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(')st.push(i);
            else{
                if(!st.empty()){
                    v[i]=i-st.top()+1;
                    if(st.top()-1>=0)v[i]+=v[st.top()-1];
                    st.pop();
                }
                else st=stack<int>();
            }
        }
        for(int i=s.size()-1;i>=0;--i){
            ret=max(ret,v[i]);
        }
        return ret;
    }
};