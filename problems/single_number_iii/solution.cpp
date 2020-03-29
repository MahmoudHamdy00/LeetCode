class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_n = nums[0];
        for (int i=1; i<nums.size(); i++) {
            xor_n = xor_n ^ nums[i];
        }
        int mask = 1;
        while((xor_n & mask)==0) {
            mask = mask<<1;
        }
        int num1;
        int num2;
        bool has1 = false;
        bool has2 = false;
        for (int num : nums) {
            if ((num & mask) == 0) {
                num1 = has1 ? (num1 ^ num) : num;
                has1 = true;
            } else {
                num2 = has2 ? (num2 ^ num) : num;
                has2 = true;
            }
        }
        return {num1, num2};
    }
};