/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q1,q2;
        q1.push(original);        
        q2.push(cloned);

        while(!q1.empty()){
            auto cur=q1.front();q1.pop();
            auto cur_cloned=q2.front();q2.pop();
            if(cur==target)return cur_cloned;
            if(cur->left)q1.push(cur->left),q2.push(cur_cloned->left);
            if(cur->right)q1.push(cur->right),q2.push(cur_cloned->right);
        }
        return NULL;
    }
};