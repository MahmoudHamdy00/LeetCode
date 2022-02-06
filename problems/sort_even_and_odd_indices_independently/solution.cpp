class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>odd,even;
        for(int i=0;i<nums.size();++i){
            if(i&1)odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(odd.rbegin(),odd.rend());    
        sort(even.begin(),even.end());
        for(int i=0,x=0,y=0;i<nums.size();++i){
            if(i&1)nums[i]=odd[x++];
            else nums[i]=even[y++];
        }
        return nums;
    }
};