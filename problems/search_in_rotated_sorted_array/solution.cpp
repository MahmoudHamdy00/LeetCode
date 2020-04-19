class Solution {
public:
    int search(vector<int>& A, int target) {
        
        int n = A.size();
        
        int left = 0;
        int right = n-1;
        
        while(left <= right){
            
            int mid = left -(left-right)/2;
            
            if(target == A[mid])
                return mid;
            
            if(A[mid] >= A[left]){
                if(A[mid] >= target && A[left] <= target) right = mid-1;
                else left = mid+1;
            }
            else{
                if(A[mid] <= target && target <= A[right])left = mid+1;
                else right = mid-1;
            }
        }
        
        return -1;
        
    }
};