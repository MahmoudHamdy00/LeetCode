#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
    ordered_set o_set;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;--i){
            auto it=o_set.order_of_key(nums[i]);
            ans[i]=it;
            o_set.insert(nums[i]);
        }
        return ans;
    }
};