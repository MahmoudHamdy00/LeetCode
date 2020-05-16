class Solution {
public:
    int maxPower(string s) {
        int mx=1,cur=1;
        for(int i=1;i<(int)s.size();i++){
            if(s[i]==s[i-1]){
                cur++;
            }
            else{
                mx=max(mx,cur);
                cur=1;
            }
        }
        return mx=max(mx,cur);
    }
};