class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        for(int i=1;i<(int)nums.size();++i){
            if(nums[k-1]!=nums[i]){
                nums[k]=nums[i];
                ++k;
            }
        }
        return k;
    }
};