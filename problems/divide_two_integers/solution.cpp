class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		long long q = 0, t = 0,a=dividend,b=divisor;
		int s = 1;
		if ((a < 0 && b > 0) || (a > 0 && b < 0))
			s = -1;
		a = abs(a), b = abs(b);
		for (int i = 31; i >= 0; i--)
		{
			if ((t + (b << i)) <= a)
			{
				t += b << i;
				q |= 1LL << i;
			}
		}
		if ((s * q) > INT_MAX)
			return INT_MAX;
		return s * q;
	}
};