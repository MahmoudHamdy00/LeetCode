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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(int i:preorder){
            root=insert(root,i);
        }
        return root;
    }
    TreeNode* insert(TreeNode* node,int val){
        TreeNode* nw=new TreeNode();
        nw->val=val;
        nw->left=NULL;
        nw->right=NULL;
        if(node==NULL){
            
            return node=nw;;
        }
        if(node->val>val){
            node->left= insert(node->left,val);
        }
        else node->right =insert(node->right,val);
        return node;
   }
};