class Solution {
    static const int N=2e5+5;
    char pattern1[N], pattern2[N];

public:
    int minFlips(string s) {
        for (int i = 0; i < N; ++i)pattern1[i] = (i & 1) + '0', pattern2[i] = (i % 2 == 0) + '0';
        int n = s.size();
        s += s;
        int choice1 = 0, choice2 = 0;
        for (int i = 0; i < n; ++i) {
            choice1 += s[i] != pattern1[i];
            choice2 += s[i] != pattern2[i];
        }
        int ans1 = choice1, ans2 = choice2;
        for (int i = n; i < 2 * n; ++i) {
            choice1 -= s[i - n] != pattern1[i - n];
            choice2 -= s[i - n] != pattern2[i - n];

            choice1 += s[i] != pattern1[i];
            choice2 += s[i] != pattern2[i];
            ans1 = min(ans1, choice1);
            ans2 = min(ans2, choice2);
        }
        return min(ans1, ans2);
    }
};