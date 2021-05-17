/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums,int l,int r) {
        if(l>r)return 0;
        int md=(l+r)>>1;
        TreeNode* cur=new TreeNode(nums[md]);
        cur->left=sortedArrayToBST(nums,l,md-1);
        cur->right=sortedArrayToBST(nums,md+1,r);
        return cur;
    }
};