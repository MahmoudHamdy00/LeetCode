class Solution {
public:
    double myPow(double x, int n) {
        double p=1;
        bool negative=n<0;
        long long nn=1LL*abs(n);
        p=poww(x,nn);
        if(negative)p=1/p;
        return p;
    }
    double poww(double x, long long n) {
        if(n==0)return 1;
        if(n==1)return x;
        double ret=poww(x,n>>1);
        ret*=ret;
        if(n&1)ret*=x;
        return ret;
    }
};