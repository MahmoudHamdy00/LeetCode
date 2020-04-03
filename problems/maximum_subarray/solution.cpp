class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		long long maxSum, curWinSlid;
		maxSum = curWinSlid = 0;
		for (int i : nums)
		{
			if (curWinSlid < 0)
				curWinSlid = i;
			else
				curWinSlid += i;
			maxSum = max(maxSum, curWinSlid);
		}
        if (maxSum > 0)
			return maxSum;
		int mx= INT_MIN;
		for (int i : nums)
		{

			mx = max(mx, i);
		}
		return mx;
	}
};