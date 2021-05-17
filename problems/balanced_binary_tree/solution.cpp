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
    bool isBalanced(TreeNode* root) {
        if(!root)return 1;

        return getHeight(root)!=1e8;
    }
    int getHeight(TreeNode* root) {
        if(!root)return -1;
        int lft=getHeight(root->left);
        if(lft==1e8)return 1e8;
        int rght=getHeight(root->right);
        if(rght==1e8)return 1e8;
        if(abs(lft-rght)>1)return 1e8;
        return max(lft,rght)+1;
    }
};