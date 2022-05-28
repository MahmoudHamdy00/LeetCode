class Solution {
public:
    bool digitCount(string num) {
        vector<int>frq(10);
        for(char ch:num)++frq[ch-'0'];
        for(int i=0;i<num.size();++i){
            if(frq[i]!=num[i]-'0')return false;
        }
        return true;
    }
};