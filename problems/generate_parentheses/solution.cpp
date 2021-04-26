class Solution {
public:
    bool check(string s){
        int cnt=0;
        for(char &ch:s){
            if(ch=='('){
                cnt++;
            }
            else cnt--;
            if(cnt<0)return 0;
        }
        return cnt==0;
    }
    vector<string> generateParenthesis(int n) {
         vector<string>ret;n*=2;
        for(int i=0;i<(1<<n);i++){
            string cur(n,'(');
            for(int j=0;j<n;j++){
                if(i&(1<<j))cur[j]=')';
            }
            if(check(cur))ret.push_back(cur);
        }
        return ret;
    }
};