class Solution {
public:
    bool isPalindrome(int x) {
        long long y=getReverse(x);
        if(x<0)return 0;
        return x==y;
    }
    long long getReverse(int x){
        long long ret=0;
        while(x){
            ret=ret*10+x%10;
            x/=10;
        }
        return ret;
    }
};