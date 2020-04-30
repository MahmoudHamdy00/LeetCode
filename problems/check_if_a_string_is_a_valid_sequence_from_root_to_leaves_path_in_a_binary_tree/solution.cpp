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
private:
    int n;
    vector<int>v;
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n=arr.size();
        v=arr;
        return helper(root,0);
    }
    bool helper(TreeNode* node,int i){
        if(i==n)return 0;
        if(!node)return 0;
        bool ok=0;
        if(node->val==v[i]&&i==n-1&&node->left==NULL&&node->right==NULL)return 1;
        if(node->val==v[i]){
            ok|=helper(node->left,i+1);
            ok|=helper(node->right,i+1);
        }
        return ok;
    }
};