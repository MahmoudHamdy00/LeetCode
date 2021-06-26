class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int prv=-1;
        for(int i=0;i<n;i++){
            bool ok=1;
            prv=-1;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(prv>=nums[j]){
                    ok=0;
                    break;
                }
                prv=nums[j];
            }
            if(ok)return 1;
        }
        return 0;
    }
};