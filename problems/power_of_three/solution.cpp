class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return 0;
        n=abs(n);
        int lg=log10(n)/log10(3);
        int nn=pow(3,lg);
        return nn==n;
    }
};