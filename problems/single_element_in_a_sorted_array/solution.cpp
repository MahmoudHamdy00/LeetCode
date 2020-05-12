class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int num=0;;
        for(int i:nums)num^=i;
        return num;
    }
};