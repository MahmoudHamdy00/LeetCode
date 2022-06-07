class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=n+m-1;i>=n;--i){
            nums1[i]=nums1[i-n];
        }
        int idx1=n,idx2=0;
        for(int i=0;i<n+m;++i){
            int num1=1e9+1,num2=1e9+1;
            if(idx1<m+n){
                num1=nums1[idx1];
            }
            if(idx2<n){
                num2=nums2[idx2];
            }
            if(num1<=num2)nums1[i]=num1,++idx1;
            else nums1[i]=num2,++idx2;
        }
    }
};