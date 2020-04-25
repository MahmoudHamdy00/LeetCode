class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        int N = nums.size();
        vector<int> opt(N, -1);
        opt[0] = nums[0];
        for (int i = 1; i < N; i++) {
            bool canJump = false;
            for (int j = i-1; j >= 0; j--) {
                if (opt[j] != -1 && opt[j] >= i-j) {
                    canJump = true;
                    break;
                }
            }
            if (canJump) opt[i] = nums[i];
        }
        return opt[N-1] != -1 ? true : false;
    }
};