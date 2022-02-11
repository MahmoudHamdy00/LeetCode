class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int i:nums)((i>0)?pos:neg).push_back(i);
        int n=nums.size();
        nums.clear();
        for(int i=0;i<n/2;++i){
            nums.push_back(pos[i]); 
            nums.push_back(neg[i]);

        }
        return nums;
    }
};