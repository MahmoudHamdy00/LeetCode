class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch=='{'||ch=='['||ch=='('){
                st.push(ch);
            }
            else if(st.empty())return 0;
            else if(ch==')'&&st.top()!='(')return 0;
            else if(ch=='}'&&st.top()!='{')return 0;
            else if(ch==']'&&st.top()!='[')return 0;
            else st.pop();
        }
        return st.empty();
    }
};