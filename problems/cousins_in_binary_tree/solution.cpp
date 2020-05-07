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
    map<int,pair<int,TreeNode*>>depth ;
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root,0,NULL);
        return (depth[x].first==depth[y].first&&depth[x].second!=depth[y].second);
    }
    void helper(TreeNode* node,int dep,TreeNode* per){
        if(node==NULL)return ;
        depth[node->val]={dep,per};
        helper(node->left,dep+1,node);
        helper(node->right,dep+1,node);
    }
};