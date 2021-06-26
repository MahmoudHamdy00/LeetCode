class Solution {
public:
	long long maxAlternatingSum(vector<int>& nums) {
		long long ans = 0;
		int i = 0, n = nums.size();
		while (i < n) {
			int cur = nums[i];
			while (i < n && cur <= nums[i]) {
				cur = nums[i];
				i++;
			}
            cout<<cur<<" ";
			ans += cur;
			if (i == n)break;
			cur = nums[i];
			while (i < n && cur >= nums[i]) {
				cur = nums[i];
				i++;
			}
            cout<<-cur<<" ";
            if(i==n)break;
			ans -= cur;
		}
        cout<<endl;
		return ans;
	}
};