/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        return checkHeight(root) != Integer.MIN_VALUE;
    }
    int checkHeight(TreeNode root) {
	if (root == null) return -1;

	int leftHeight = checkHeight(root.left);
	if (leftHeight== Integer.MIN_VALUE) return Integer.MIN_VALUE; // Pass error up 

	int rightHeight= checkHeight(root.right);
	if (rightHeight == Integer.MIN_VALUE) return Integer.MIN_VALUE; // Pass error up 

	int heightDiff = leftHeight - rightHeight;
	if (Math.abs(heightDiff) > 1) {
		return Integer.MIN_VALUE; // Found error -> pass it back 
	}
	else {
		return Math.max(leftHeight, rightHeight) + 1;
	}
}
}