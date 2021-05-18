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
    int mp[20000005];
    int N=10000000;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)return 0;
        mp[0+N]++;
        return pathSum1(root,0,targetSum);
    }
    int pathSum1(TreeNode* root, int curSum,int &targetSum) {
        if(root==nullptr)return 0;
        curSum+=root->val;
        int ret=mp[(curSum-targetSum)+N];
        mp[curSum+N]++;
        ret+=pathSum1(root->left,curSum,targetSum);
        ret+=pathSum1(root->right,curSum,targetSum);
        mp[curSum+N]--;
        return ret;
    }
};