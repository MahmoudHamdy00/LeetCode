class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        while(x){
            rev*=10;
            rev+=x%10;
            x/=10;
        }
        if(rev>=INT_MAX||rev<=INT_MIN)return 0;
        x=rev;
        return x;
    }
};