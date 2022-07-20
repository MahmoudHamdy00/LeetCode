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
    map<int,int>inorderToIndex;
    int rootIndex;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();++i){
            inorderToIndex[inorder[i]]=i;
        }
        rootIndex=0;
        return build(0,inorder.size()-1,preorder);
    }
    TreeNode* build(int l,int r,vector<int>& preorder){
        if(l>r)return NULL;
        int rootValue=preorder[rootIndex++];
        TreeNode* curRoot=new TreeNode(rootValue);
        curRoot->left=build(l,inorderToIndex[rootValue]-1,preorder);
        curRoot->right=build(inorderToIndex[rootValue]+1,r,preorder);
        return curRoot;
        
    }
};