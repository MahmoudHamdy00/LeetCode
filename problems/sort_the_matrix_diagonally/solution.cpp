class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int n = mat.size();
		int m = mat[0].size();
		int cnt = n + m - 1, mm = m - 1, pls = 0;
		vector<vector<int>>ret, ans(n, vector<int>(m));
		while (cnt--) {
			vector<int>tmp;
			int i = pls, j = mm + pls;
			while (i < n && j < m) {
				tmp.push_back(mat[i][j]);
				i++, j++;
			}
			sort(tmp.begin(),tmp.end());
			ret.push_back(tmp);
			mm--;
			if (mm < 0)pls++;
		}
		cnt = ret.size();
		pls = 0, n--, m--;
		for (int i = 0; i < cnt; i++) {
			int ii = pls, jj = m + pls;
			for (int j = 0; j < ret[i].size(); j++) {
				ans[ii][jj] = ret[i][j];
				ii++, jj++;
			}
			m--;
			if (m < 0)pls++;;
		}
		return ans;
	}
};