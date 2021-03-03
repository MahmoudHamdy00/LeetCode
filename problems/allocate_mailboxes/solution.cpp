class Solution {
private:
	int n;
	vector<vector<int>>pre;
    int mem[105][105];
public:
	int minDistance(vector<int>& houses, int k) {
		n = houses.size();
		sort(houses.begin(), houses.end());
		pre = vector<vector<int>>(n, vector<int>(n));
		memset(mem,-1,sizeof mem);
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int md = j - i >> 1;
				for (int l = i,r=j; l<=r; l++,r--) {
					pre[i][j] += abs(houses[r] - houses[l]);
				
				}
			}
		}
		return solve(0, k);
	}
	int solve(int i, int k) {
		if (k < 0)return 1e9;
		if (i == n)return (k == 0 ? 0 : 1e9);
        int&ret=mem[i][k];
        if(ret!=-1)return ret;
        ret = 1e9;
		for (int j = i; j < n; j++) {
			ret = min(ret, pre[i][j] + solve(j + 1, k - 1));
		}
		return  ret;
	}
};