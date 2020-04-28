class Solution
{
public:
	int divide(int dividend, int divisor)
	{
        long long ret=1LL*dividend/divisor;
		return (ret>INT_MAX?INT_MAX:ret);
	}
};