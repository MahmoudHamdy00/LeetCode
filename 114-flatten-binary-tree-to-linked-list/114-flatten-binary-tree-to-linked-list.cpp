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
    vector<int>v;
public:
    void flatten(TreeNode* root) {
        build(root);
        for(int i=0;i<v.size();++i){
            root->val=v[i];
            root->left=nullptr;
            if(i!=v.size()-1&&!root->right)root->right=new TreeNode();
            root=root->right;
            
        }
    }
    void build(TreeNode *root){
        if(!root)return;
        v.push_back(root->val);
        build(root->left);
        build(root->right);
    }
};