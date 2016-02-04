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
    public boolean hasPathSum(TreeNode root, int sum) {
        
        if(root==null)
            return false;
        
        if(root.val==sum && root.left==null && root.right==null) // not consider root to LEAVE
            return true;
       
        // the value can be negative
            sum = sum - root.val;
            if(root.left!=null && hasPathSum(root.left,sum)) return true;
            if(root.right!=null && hasPathSum(root.right,sum)) return true;
        
        return false;
        
    }
}