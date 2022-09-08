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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int>ret;
        auto pre=inorderTraversal(root->left);
        ret.insert(ret.end(),pre.begin(),pre.end());
        ret.push_back(root->val);
        auto nxt=inorderTraversal(root->right);
        ret.insert(ret.end(),nxt.begin(),nxt.end());
        return ret;
    }
};