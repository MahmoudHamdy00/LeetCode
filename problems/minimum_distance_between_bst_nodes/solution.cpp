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
    int minDiffInBST(TreeNode* root) {
       queue<TreeNode*>q;
        vector<int>v;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            v.push_back(cur->val);
            if(cur->left!=NULL){
                q.push(cur->left);
            }
             if(cur->right!=NULL){
                q.push(cur->right);
            }
        }
        sort(v.begin(),v.end());
        int mn=1e9;
        for(int i=1;i<v.size();i++){
            mn=min(mn,v[i]-v[i-1]);
        }
        return mn;
    }
};