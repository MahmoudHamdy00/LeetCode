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
    vector<int>inorder;int K;
public:
    int kthSmallest(TreeNode* root, int k) {
        K=k;
        build(root);
        return inorder[k-1];
    }
    void build(TreeNode* node){
        if(!node||inorder.size()>=K)return;
        build(node->left);
        inorder.push_back(node->val);
        build(node->right);
        return;
    }
};