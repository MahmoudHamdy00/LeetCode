class Solution {
public:
    int numSteps(string s) {
        int cnt=0;
        while(s.size()>1){
            ++cnt;
            if(s.back()=='0')s.pop_back();
            else{
                for(int i=s.size();i>=0;--i){
                    if(s[i]=='0'){
                        s[i]='1';
                        break;
                    }
                    s[i]='0';
                }
                if(s[0]=='0')s='1'+s;
            }
        }
        return cnt;
    }
};