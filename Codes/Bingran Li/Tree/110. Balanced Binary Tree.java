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
    public boolean isBalanced(TreeNode root) {
        // solution 1: too slow (5.7%)
        if(root==null)
            return true;
        TreeNode currentNode;
        int differ;
        
        currentNode = root;
        differ =  height(currentNode.left)-height(currentNode.right);
        if(differ>1||differ<-1) // used to be differ*differ>1-----from 8ms to 7ms
            return false;
        boolean left = isBalanced(currentNode.left);
        if(!left)
            return false;
        boolean right = isBalanced(currentNode.right);
        if(!right)
            return false;
        
        return true;
        
    }
    
    public int height(TreeNode root){
        
        if(root==null)
         return -1;
         // ********do not call it again and again*****
         int l=  height(root.left);
         int r=  height(root.right);
         /*  
        if(root.left==null && root.right==null) 
            return 0;
        if(root.left==null)
            return r+1;
        if(root.right==null)
            return l+1;
        */
        int height=0;
        height = r>l? r: l;
        
        return height+1;
    }
    
    
    
    
    
}