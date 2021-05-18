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
    map<pair<TreeNode* , int >,bool>mem;
    vector<vector<int>> ret;
    vector<int>tmp;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        hasPathSum(root,targetSum);
        return ret;
    }
    void hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return;
        tmp.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&targetSum-root->val==0){
            ret.push_back(tmp);
        }
        hasPathSum(root->left,targetSum-root->val);
        hasPathSum(root->right,targetSum-root->val);
        tmp.pop_back();
    }
    
};