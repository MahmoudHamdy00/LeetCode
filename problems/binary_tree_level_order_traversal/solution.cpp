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
    vector<vector<int>>ret;
    map<int,vector<int>>mp;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        ret.push_back({root->val});
        build(root,0);
        for(auto it:mp)ret.push_back(it.second);
        return ret;
    }
    void build(TreeNode* root,int order){
        if(root==nullptr)return ;
        if(root->left!=nullptr)
            mp[order].push_back(root->left->val);
        if(root->right!=nullptr)
            mp[order].push_back(root->right->val);
        build(root->left,order+1);
        build(root->right,order+1);
        return;
    }
};