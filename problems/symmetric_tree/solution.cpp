
 
class Solution {
public:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if(left == NULL && right == NULL) {
            return true;
        } else if(left == NULL || right == NULL) {
            return false;
        }
        
        return left->val == right->val &&
                isSymmetric(left->right, right->left) &&
                isSymmetric(left->left, right->right);
    }
    
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
};