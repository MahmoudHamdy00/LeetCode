class Solution {
public:
    int countElements(vector<int>& arr) {
        int arr1[1002]={0};
        for(int i:arr)arr1[i]++;
        int cnt=0;
        for(int i=0;i<=1000;i++){
            if(arr1[i]&&arr1[i+1])cnt+=arr1[i];
        }
        return  cnt;
    }
};