class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i + 3 <= 9; i += 3) {
			for (int j = 0; j + 3 <= 9; j += 3) {
				//3*3
				vector<int>frq(10);
				for (int a = i; a < i + 3; a++) {
					for (int b = j; b < j + 3; b++) {
						if (board[a][b] == '.')continue;
						if (++frq[board[a][b] - '0'] > 1)
							return 0;
					}
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			vector<int>frq(10);
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')continue;
				if (++frq[board[i][j] - '0'] > 1)return 0;
			}
		}
		for (int j = 0; j < 9; j++) {
			vector<int>frq(10);
			for (int i = 0; i < 9; i++) {
				if (board[i][j] == '.')continue;
				if (++frq[board[i][j] - '0'] > 1)return 0;
			}
		}
        return 1;
	}
};