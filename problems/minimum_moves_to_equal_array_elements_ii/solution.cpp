class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size() - 1, moves = 0;
        while (left < right)
            moves += nums [right--] - nums [left++];
        return moves;
    }
};