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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr)return 1;
        if(root==nullptr)return 0;
        string s,k;
        get(root,s);
        get(subRoot,k);
        int idx=s.find(k);
        while(idx!=-1){
            if(idx==0)return true;
            if(s[idx-1]==' ')return true;
            idx=s.find(k,idx+1);
        }
        return false;
    }
    void get(TreeNode* root,string&s) {
        if(root==nullptr){
            s+="X ";
            return ;
        }
        get(root->left,s);
        get(root->right,s);
        s+=to_string(root->val)+" ";
    }
};