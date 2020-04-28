class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int idx=nums1.size();
        if(idx&1){
            double ret=nums1[idx/2];
            return ret;
        }
        else{
            double ret=nums1[idx/2-1]+nums1[idx/2];
            return ret/2;
        }
    }
};