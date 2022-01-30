class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool ok=1;
        do{
            ok=0;
            for(int i:nums){
                if(i==original){
                    ok=1;
                    break;
                }
            }
            if(ok)
            original*=2;
        }while(ok);
        return original;
    }
};