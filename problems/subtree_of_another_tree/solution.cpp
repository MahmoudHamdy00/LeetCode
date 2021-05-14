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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr)return 1;
        if(root==nullptr)return 0;
        bool ret=0;
        if(isIdentical(root,subRoot))
           return true;
        ret|=isSubtree( root->right,  subRoot);
        ret|=isSubtree( root->left,  subRoot);
        return ret;
    }
    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr&&subRoot==nullptr)return true;
        if(root==nullptr||subRoot==nullptr)return false;
        if(root->val!=subRoot->val)return false;
        return isIdentical(root->left,subRoot->left)&isIdentical(root->right,subRoot->right);

    }
};