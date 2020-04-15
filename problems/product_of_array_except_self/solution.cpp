class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int>l = nums, r = nums;
	for (int i = 1; i < n; i++) {
		l[i] *= l[i - 1];
	}
	for (int i = n - 2; i >= 0; i--) {
		r[i] *= r[i + 1];
	}
	vector<int>ret(n);
	for (int i = 0; i < n; i++) {
		int left = 1;
		int right = 1;
		if (i)left = l[i - 1];
		if (i != n - 1)right = r[i + 1];
		ret[i]= left * right;
	}
        return ret;
    }
};