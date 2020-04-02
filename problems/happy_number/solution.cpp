class Solution
{
public:
	bool isHappy(int n)
	{
		map<int, int> mp;
		while (1)
		{
			int sum = 0;
			while (n > 0)
			{
				sum += (n % 10) * (n % 10);
				n /= 10;
			}
			if (sum == 1)
				return 1;
			n = sum;
			if (mp.find(n) != mp.end())
				return 0;
			mp[sum]++;
		}
	}
};