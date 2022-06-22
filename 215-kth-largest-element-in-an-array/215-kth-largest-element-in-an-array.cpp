class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N=1e4;
        int arr[2*N+5]={0};
        for(int i:nums)++arr[i+N];
        for(int i=N;i>=-N;--i){
            k-=arr[i+N];
            if(k<=0)return i;
        }
        return NULL;
    }
};