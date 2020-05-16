class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
        int n=(int)A.size();
        
		long long sumAll = 0, maxSum = LLONG_MIN, minSum = LLONG_MAX, ans = LLONG_MIN;

		long long temp_maxSUM = 0, temp_minSUM = 0;

		for (int i = 0; i < n; ++i)
		{
			sumAll += A[i];

			temp_maxSUM += A[i];
			maxSum = max(maxSum, temp_maxSUM);
			temp_maxSUM = max(temp_maxSUM, 0LL);

			temp_minSUM += A[i];
			minSum = min(minSum, temp_minSUM);
			temp_minSUM = min(temp_minSUM, 0LL);
		}
		if (sumAll == minSum)
			ans= maxSum;
        else
		ans= max(maxSum, (sumAll - minSum));
		return ans;
	}
};