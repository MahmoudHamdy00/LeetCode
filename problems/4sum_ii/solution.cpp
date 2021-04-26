class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mp1,mp2;
        for(int &i:nums1){
            for(int &j:nums2){
                mp1[i+j]++;
            }
        }
        for(int &i:nums3){
            for(int &j:nums4){
                mp2[i+j]++;
            }
        }
        int cnt=0;
        for(auto &i:mp1){
            for(auto &j:mp2){
                if(i.first+j.first==0)cnt+=i.second*j.second;
            }
        }
        return cnt;
    }
};