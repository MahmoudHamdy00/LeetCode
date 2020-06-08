class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return 0;
        long long N=log2(n);
        return (1LL<<N)==n;
    }
};