class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len=0;
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]==1){
                if(len<k&&i!=0)return false;
                len=0;
            }
            else len++;
        }
        return true;
    }
};