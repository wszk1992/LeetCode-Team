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
    public int minDepth(TreeNode root) {
        
        // how to solve this by DFS and BFS
        // good video about DFS and BFS---    https://www.youtube.com/watch?v=bIA8HEEUxZI
        if(root==null) return 0;
        
        int left,right;
        
        if(root.left==null && root.right==null)
            return 1;
            
        if(root.left!=null && root.right!=null)  {
            left = minDepth(root.left);
            right = minDepth(root.right);
            int dep = left<right ? left:right;
            return dep+1;
        }  
            
        if(root.left !=null){
            left = minDepth(root.left);
            return left+1;
        }
        if(root.right!=null){
            right = minDepth(root.right);
            return right+1;
        }
        
        return 0;
    }
}