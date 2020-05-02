class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ret=0;
        for(char ch:S){
            if (J.find(ch)!=string::npos)ret++;
        }
        return ret;
    }
};