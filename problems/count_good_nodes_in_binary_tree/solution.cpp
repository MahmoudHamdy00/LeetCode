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
    int goodNodes(TreeNode* root) {
        return solve(root,-1e5);
    }
    int solve(TreeNode* node,int mx){
        if(node==NULL)return 0;
        int ret=0;
        if(node->val>=mx)ret+=1;
        ret+=solve(node->left,max(mx,node->val));
        ret+=solve(node->right,max(mx,node->val));
        return ret;
    }
};