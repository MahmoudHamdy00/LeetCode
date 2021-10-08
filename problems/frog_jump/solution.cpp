class Solution {
public:
	int n, lst;
	set<int>st;
	map<pair<int, int>, int>mem;
	bool canCross(vector<int>& stones) {
		n = stones.size();
		lst = stones.back();
		for (int i = 0; i < stones.size(); ++i)st.insert(stones[i]);

		return solve(0, 0, stones);
	}
	bool solve(int i, int k, vector<int>& stones) {
		if (i == n - 1)return 1;
		if (mem.find({ i,k }) != mem.end())return mem[{ i, k }];
		int ret = 0;
		ret = 0;
		int j = i + 1;
		while (j < n && stones[j] - stones[i] < k - 1)++j;
		while (j > i && j < n && stones[j] - stones[i] <= k + 1) {
			ret |= solve(j, stones[j] - stones[i], stones);
			++j;
		}

		return mem[{ i, k }] = ret;
	}
};