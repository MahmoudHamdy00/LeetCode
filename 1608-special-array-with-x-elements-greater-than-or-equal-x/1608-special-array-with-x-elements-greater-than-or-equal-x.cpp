class Solution {
public:
    int specialArray(vector<int>& nums) {
        int frq[1005]={0},cnt=nums.size();
        for(int i=0;i<nums.size();++i){
            ++frq[nums[i]];
        }
        for(int i=0;i<=1000;++i){
            if(cnt==i){
                return i;
            }
            cnt-=frq[i];
        }
        return -1;
    }
};