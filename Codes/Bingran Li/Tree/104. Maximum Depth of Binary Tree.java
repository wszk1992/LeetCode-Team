/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int maxDepth(TreeNode root) {
        
        // solution 1: 
        if(root==null)
            return 0;
        if(root.left==null && root.right==null)
            return 1;
        else if(root.left==null)
            return maxDepth(root.right)+1;
        else if(root.right==null)
            return maxDepth(root.left)+1;
        else{
            int max;
            int right = maxDepth(root.right);
            int left = maxDepth(root.left);
             max = right>left ? right:left;
            // there used to be ------time exceed--->WHY????
            // max = maxDepth(root.right)>maxDepth(root.left)?maxDepth(root.right):maxDepth(root.left);
            return max+1;
        }
            
    }
}