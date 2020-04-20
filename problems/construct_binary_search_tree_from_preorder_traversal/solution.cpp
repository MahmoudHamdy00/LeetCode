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
    vector<int> pre;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        pre=preorder;
        int preIndex = 0;  
        return constructTreeUtil ( &preIndex, 0, pre.size() - 1);  
    }
   TreeNode* newNode (int data)  
{  
    TreeNode* temp = new TreeNode(); 
  
    temp->val = data;  
    temp->left = temp->right = NULL;  
  
    return temp;  
}  
  
// A recursive function to construct Full from pre[]. preIndex is used  
// to keep track of index in pre[].  
TreeNode* constructTreeUtil ( int* preIndex, int low, int high)  
{  
    // Base case  
    if (*preIndex >= pre.size() || low > high)  
        return NULL;  
  
    // The first node in preorder traversal is root. So take the node at  
    // preIndex from pre[] and make it root, and increment preIndex  
    TreeNode* root = newNode ( pre[*preIndex] );  
    *preIndex = *preIndex + 1;  
  
    // If the current subarry has only one element, no need to recur  
    if (low == high)  
        return root;  
  
    // Search for the first element greater than root  
    int i;  
    for ( i = low; i <= high; ++i )  
        if ( pre[ i ] > root->val )  
            break;  
  
    // Use the index of element found in preorder to divide  
        // preorder array in two parts. Left subtree and right subtree  
    root->left = constructTreeUtil ( preIndex, *preIndex, i - 1 );  
    root->right = constructTreeUtil (  preIndex, i, high );  
  
    return root;  
}  
  

  

};