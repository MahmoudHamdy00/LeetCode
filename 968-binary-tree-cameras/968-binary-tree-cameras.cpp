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
    int minCameraCover(TreeNode* root) {
        int cnt=0;
        int ret=minCameraCover(root,cnt);
        return ret&1?cnt+1:cnt;
    }
    int minCameraCover(TreeNode* node,int &cnt) {
        if(!node)return 0;
        if(!node->left&&!node->right)return 1;
        
        auto L=minCameraCover(node->left,cnt);
        
        auto R=minCameraCover(node->right,cnt);
        
        if(L==1||R==1){
            ++cnt;
            return 2;
        }
        if(L==2||R==2){
            return 0;
        }

        return 1;   
    }
  
};