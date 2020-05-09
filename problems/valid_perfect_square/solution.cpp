class Solution {
public:
    bool isPerfectSquare(int num) {
        long long n=INT_MAX;
        for (long long i=0;i*i<=n;i++){
            if(i*i==num)return true;;
        }
        return false;
    }
};