class Solution {
private:
    int ans=INT_MIN;  
    int maxPath( TreeNode* node ) {
        if( !node ) return 0;
        int left = max(0,maxPath(node->left));
        int right = max(0,maxPath(node->right));
        ans=max(ans,left+right+node->val);
        return node->val+max(left,right);
    }
    
public:
    int maxPathSum( TreeNode* root ) {
        maxPath( root );
        return ans;
    }
};