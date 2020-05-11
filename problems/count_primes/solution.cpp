class Solution {
public:
    int countPrimes(int n) {
        bitset<(int)1e8>isPrime;
        isPrime[0]=isPrime[1]=1;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i])continue;
            for(int j=i*i;j<n;j+=i){
                isPrime[j]=1;
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++)if(isPrime[i]==0)cnt++;
        return cnt;
    }
};