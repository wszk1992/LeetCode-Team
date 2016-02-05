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
    public List<String> binaryTreePaths(TreeNode root) {
        
        String myString = new String();
        List myList = new ArrayList();
        subPath(root,myString,myList);
        return myList;
        
    }
    public void subPath(TreeNode root, String tem,List myList){
       
        // solution 1: recursive
        if(root==null)   return;
        // method 1: in this way it create a new string, not affect old one
        // s += "->" + Integer.toString(root.val);
        // method 2: create a new string
         String s = tem+"->" + Integer.toString(root.val); // a safe way
        // method 3: (based on the original one)
        // this "s.concat(myString)" will return a new string, you need to use a new string to hold it
        // from s.concat() to tem=s.concat();
        if(root.left!=null)    subPath(root.left,s,myList);
        if(root.right!=null)   subPath(root.right,s,myList);
        // then left and right both are null
        if(root.right==null && root.left==null)  {
           
             myList.add(s.substring(2));
        
        }
       
    }
    
    
    
}