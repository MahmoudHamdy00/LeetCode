class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret=0;
        long long prv=1;
        for(int i=columnTitle.size()-1;i>=0;i--){
            int tmp=columnTitle[i]-'A'+1;
            ret+=prv*tmp;
            prv*=26;
        }
        return ret;
    
    }
};