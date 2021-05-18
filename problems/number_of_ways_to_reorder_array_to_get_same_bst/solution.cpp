class Solution {
    long long fact[1005], mod = 1e9 + 7;//, inv[1005];
public:
    int numOfWays(vector<int>& nums) {
        fact[0] = fact[1] = 1;
        for (int i = 2; i <= 1000; i++)fact[i] = (fact[i - 1] * i) % mod,fact[i]%=mod;
       // for (int i = 2; i <= 1000; i++)inv[i] = power(fact[i], mod - 2);
        return helper(nums) -1% mod;
    }

    long long power(long long x, long long y) {
        if (y == 0)return 1;
        long long ret = power(x, y >> 1) % mod;
        ret *= ret;
        ret %= mod;
        if (y & 1)ret *= x;
        return ret % mod;
    }
    long long helper(vector<int>& nums) {
        if (nums.empty())return 1;
        vector<int>left, right;
        for (int i = 1; i < nums.size(); i++) {
            (nums[i] > nums.front() ? right : left).push_back(nums[i]);
        }
        long long ret = (helper(left) * helper(right)) % mod;
        int n = left.size(), m = right.size();
        long long haha=power((fact[n]%mod*fact[m]%mod)%mod,mod-2);
        ret = ((fact[n+m]%mod*haha)%mod*ret)%mod;
            return ret ;
    }

};