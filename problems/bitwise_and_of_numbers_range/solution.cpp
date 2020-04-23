class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret=n;
        for(int i=m;i<n;i++){
            ret&=i;
            if(!ret)return ret;
        }
        return ret;
    }
};