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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
       
       
       // solution 2: use the val of each node
       if(p.val<root.val&&q.val<root.val)
            return lowestCommonAncestor(root.left,p,q);
       if(p.val>root.val&&q.val>root.val)
            return lowestCommonAncestor(root.right,p,q);
        
       return root;
       
       
       // solution 1: easy to understand, but too slow(2%), did not use the property of BST
       /*
        if(isChild(root,p)==false || isChild(root,q)==false)
            return null;
        else{
            // the root has two node, then check left and right
            if(isChild(root.left,p)&&isChild(root.left,q))
                return lowestCommonAncestor(root.left,p,q);
            else if(isChild(root.right,p)&&isChild(root.right,q))
                return lowestCommonAncestor(root.right,p,q);
            // left right do not have both, return root
            else 
                return root;
        }
     */
    }
 /*   
    public boolean isChild(TreeNode root, TreeNode myNode){
      
        // if find that node, then return true
        if(root==null)
            return false;
        
        if(root==myNode)
            return true;
        
        if(isChild(root.left, myNode)) return true;
        if(isChild(root.right,myNode)) return true;
        
        return false;
    }
   */ 
}