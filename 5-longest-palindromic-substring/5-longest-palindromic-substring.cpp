class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int cur = 1;
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                cur += 2;
                --l, ++r;
            }
            mx = max(mx, cur);
        }
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                cur += 2;
                --l, ++r;
            }
            mx = max(mx, cur);
        }
        for (int i = 0; i < n; ++i) {
            int cur = 1;
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                cur += 2;
                --l, ++r;
            }
            if (cur == mx) {
                string ans = "";
                for (int j = i - cur / 2; j <= i + cur / 2; ++j)ans += s[j];
                return ans;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                cur += 2;
                --l, ++r;
            }
            if (cur == mx) {
                string ans = "";
                //   cout<<cur<<" "<<i-cur<<endl;
                for (int j = i - cur / 2+1; j <= i + cur / 2; ++j)ans += s[j];
                return ans;
            }
        }
        return "";
    }
};