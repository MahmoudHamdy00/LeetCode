class Solution {
    int mem[100005][5][2];
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        memset(mem,-1,sizeof mem);
        return max(solve(0,0,0,nums1,nums2),solve(0,0,1,nums2,nums1));
    }
    int solve(int i,int take,int w,vector<int>& nums1, vector<int>& nums2) {
        if(i==nums1.size())return 0;
        int &ret=mem[i][take][w];
        if(~ret)return ret;
        ret=0;
        if(take==0)
            ret=max(ret,solve(i+1,0,w,nums1,nums2)+nums1[i]),
            ret=max(ret,solve(i+1,1,w,nums1,nums2)+nums2[i]);
        if(take==1)
            ret=max(ret,solve(i+1,1,w,nums1,nums2)+nums2[i]),
            ret=max(ret,solve(i+1,2,w,nums1,nums2)+nums1[i]);
        if(take==2)
            ret=max(ret,solve(i+1,2,w,nums1,nums2)+nums1[i]);
        return ret;
    }
};