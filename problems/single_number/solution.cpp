class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xOr=0;
        for(int i:nums)xOr^=i;
    
    return xOr;
    }
};