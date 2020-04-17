class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int,char>>st,st2;
        int cnt=0,i=0;
        for(char ch:s){
            if(ch=='(')st.push({i,ch});
            else if(ch=='*')st2.push({i,ch});
            else {
                if(st.empty()&&st2.empty())return 0;
                else if(!st.empty())st.pop();
                else st2.pop();
            }
            i++;
        }
        if(st2.size()<st.size())return 0;
        while(!st.empty()){
            if((int)st.top().first>(int)st2.top().first)return 0;
            st.pop();
            st2.pop();
        }
        return 1;
    }
};