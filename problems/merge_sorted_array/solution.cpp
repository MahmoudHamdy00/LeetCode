class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sz=m+n-1;
        int i=m-1,j=n-1;
       
        for(int cur=m+n-1;cur>=0;cur--){
            int num=0;
            if(i>=0&&j>=0){
               if(nums1[i]>nums2[j]){
                    num=nums1[i--];
                }
                else{
                    num=nums2[j--];
                }
            }
            else if(i>=0){
                num=nums1[i--];
            }
            else{
                num=nums2[j--];
            }

            nums1[cur]=num;
        }
    }
};