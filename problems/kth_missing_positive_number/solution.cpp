class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur=1;
        int cnt=k;
        for(int i= 0;i<arr.size()  ;i++,cur++){
         while(cur!=arr[i])
         {
             k--;
             if(!k){
                 return cur;
             }
             cur++;
         }
       } 
        return arr.back()+k;
    }
};