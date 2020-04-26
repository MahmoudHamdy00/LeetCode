class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0,mx=0;
        for(int i:nums){
            if(i==1)cur++;
            else {
                if(mx<cur)
                  mx=cur;
                cur=0;
            }
            
        }
        if(mx<cur)
            mx=cur;
        return mx;
    }
};