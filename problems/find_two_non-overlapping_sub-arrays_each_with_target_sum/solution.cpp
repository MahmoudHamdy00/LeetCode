class Solution {

public:
	int minSumOfLengths(vector<int>& arr, int target) {
		map<int, int>mp;
		int n = arr.size();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			mp[sum] = i;
		}
		int ans = INT_MAX; sum = 0;
		int curLen = INT_MAX;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if (sum == target)
				curLen = min(curLen, mp[sum] + 1);
			else if (mp.find(sum - target) != mp.end()) {
				curLen = min(curLen, i - mp[sum - target]);
			}
			if (mp.find(sum + target) != mp.end() && curLen != INT_MAX) {
				ans = min(ans, mp[sum + target] - i + curLen);
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};