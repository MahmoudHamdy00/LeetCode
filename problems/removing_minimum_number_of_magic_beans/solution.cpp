#include <bits/stdc++.h>
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long N = beans.size(), ans = LLONG_MAX, sum = accumulate(begin(beans), end(beans), 0L);
        sort(begin(beans), end(beans));
        for (int i = 0; i < N; ++i) ans = min(ans, sum - (N - i) * beans[i]);
        return ans;
    }
};