class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ret=0;
        int prv=0;
        for(int i=0;i<brackets.size();++i){
            int cur=min(income,brackets[i][0])-prv;
            ret+=cur*brackets[i][1];
            if(income<brackets[i][0])break;
            prv=brackets[i][0];
        }
        return ret/100;
    }
};