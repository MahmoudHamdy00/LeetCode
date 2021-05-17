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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return 1;
        return isValidBST(root,1e10,1e10);
    }
    bool isValidBST(TreeNode* root,long long mn,long long mx) {
        if(root==nullptr)return 1;
        if(mn!=1e10&&root->val<=mn||mx!=1e10&&root->val>=mx)return 0;
        if(!isValidBST(root->left,mn,root->val)||!isValidBST(root->right,root->val,mx))
        return 0;
        return 1;
    }
};