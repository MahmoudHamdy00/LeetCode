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
    long long  lst=1e10;
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return 1;
        if(!isValidBST(root->left))return false;
        if(lst!=1e10&&lst>=root->val)return false;
        lst=root->val;
        if(!isValidBST(root->right))return false;
        return true;
    }
};