class Solution {
    int frq1[1001],frq2[1001];
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            frq1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            frq2[nums2[i]]++;
        }
        vector<int>ret;
        for(int i=0;i<=1000;i++){
            int cnt=min(frq1[i],frq2[i]);
            while(cnt--){
                ret.push_back(i);
            }
        }
        return ret;
    }
};