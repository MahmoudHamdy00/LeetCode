class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Time Complexity: O(n^2)
        // Space Complexity: O(n)
        
        int n=(int)(arr.size()), ans=0;
        vector<int>pre;
        pre.push_back(0);
        for (int i = 0; i < n; ++i)
            pre.push_back(arr[i]^pre.back());
        
        for (int i = 1; i < n; ++i)
            for (int k = i + 1; k <= n; ++k)
                if (pre[i-1] == pre[k])
                    ans += k - i;
        return ans;
    }
};