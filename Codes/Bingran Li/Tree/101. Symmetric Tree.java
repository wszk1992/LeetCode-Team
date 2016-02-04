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
    
    public boolean isSame(TreeNode node1,TreeNode node2){
        
        if(node1==null && node2==null) return true;
        if(node1==null || node2==null)  return false;
        if(node1.val!=node2.val) return false;
        
        return isSame(node1.left,node2.right) && isSame(node1.right,node2.left); // ******core code****
    }
    
    
    public boolean isSymmetric(TreeNode root) {
        
        // solution 2: muy bien
        
        return isSame(root,root);
        
        
        
        // solution 1: not good, didn't consider null point
        /*
        if(root==null)  
            return true;
            
        ArrayList leftList = new ArrayList <Integer>();
        ArrayList rightList = new ArrayList <Integer>();
        
        int dep = depth(root); // the depth of root
        
        traversal(root.left, leftList,true,dep);
        traversal(root.right,rightList,false,dep);
        
        if(leftList.size()!=rightList.size())
            return false;
            
        int size = leftList.size();
        for(int i=0;i<size;i++){
            if(leftList.get(i)!=rightList.get(i))
                 return false;
        }
        return true;
        */
    }
    /*
    public void traversal(TreeNode root, ArrayList  myList,boolean isLeft, int dep){
        if(root==null){
            if(dep<=0)
                return;
            else{
                myList.add('#');
                return;
            }
        }
            
        myList.add(root.val);
        
        if(isLeft){
            traversal(root.left,myList,true,dep-1);
            traversal(root.right,myList,true,dep-1);
        }
        else{
           
            traversal(root.right,myList,false,dep-1);
            traversal(root.left,myList,false,dep-1);
        }
    }
    public int depth(TreeNode root){
        // assume root is not null
        if(root.left==null && root.right==null)
            return 0;
        else if(root.left==null)  
            return depth(root.right) +1;
        else
            return depth(root.left) +1;
    }
    */
    
}