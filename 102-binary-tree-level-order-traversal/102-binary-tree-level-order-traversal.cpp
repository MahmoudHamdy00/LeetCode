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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        vector<vector<int>>ret;
        queue<TreeNode*>q;
        q.push(root);
        int sz;
        do{
            sz=q.size();
            vector<int>currentLevel;
            while(sz--){
                TreeNode* currentNode=q.front();q.pop();
                currentLevel.push_back(currentNode->val);
                if(currentNode->left)
                    q.push(currentNode->left);
                if(currentNode->right)   
                    q.push(currentNode->right);
            }
            ret.push_back(currentLevel);
        }while(!q.empty());
        return ret;
    }
};