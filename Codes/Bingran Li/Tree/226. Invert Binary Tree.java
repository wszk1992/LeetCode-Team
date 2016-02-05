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
    public TreeNode invertTree(TreeNode root) {
        
       if(root==null|| (root.left==null && root.right==null)) // add a judgement to reduce operation, reduce from 1ms to 0ms
            return root;
            
        TreeNode temNode = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(temNode);
  
        return root;
    }
 
}