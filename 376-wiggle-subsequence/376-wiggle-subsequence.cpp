class Solution {
    int mem[1001][1002][2];
public:
    int wiggleMaxLength(vector<int>& nums) {
        memset(mem,-1,sizeof mem);
        int ret=wiggleMaxLength(0,-1,0,nums);
        memset(mem,-1,sizeof mem);
        ret=max(ret,wiggleMaxLength(0,-1,1,nums));

        return ret;
    }
    int wiggleMaxLength(int i,int lst,bool is_positive,vector<int>& nums) {
        if(i==nums.size())return 0;
        int &ret=mem[i][lst+1][is_positive];
        if(~ret)return ret;
        ret=wiggleMaxLength(i+1,lst,is_positive,nums);
        if(is_positive){
            if(lst==-1||nums[i]>lst)ret=max(ret,wiggleMaxLength(i+1,nums[i],!is_positive,nums)+1);
        }
        else{
            if(lst==-1||nums[i]<lst)ret=max(ret,wiggleMaxLength(i+1,nums[i],!is_positive,nums)+1);
        }
        return ret;
    }
};