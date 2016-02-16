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
    public List<Integer> inorderTraversal(TreeNode root) {
        
       // solution 2: iterative 
        
        List<Integer> myList = new ArrayList();
        
        if(root==null)
            return myList;
        
        Stack<TreeNode> myStack = new Stack<TreeNode>();
        TreeNode cur = root;
        
        while(cur!=null||!myStack.empty()){
            while(cur!=null){
                myStack.push(cur);
                cur = cur.left;
            }
            cur = myStack.pop();
            myList.add(cur.val);
            cur = cur.right;
        }
        
        return myList;
        
        // solution 1: recursive
        /*
        List<Integer> myList = new ArrayList<Integer>();
        if(root==null)
            return myList;
            
        List<Integer> left = inorderTraversal(root.left);
        List<Integer> right = inorderTraversal(root.right);
        
        myList.addAll(left);
        myList.add(root.val);
        myList.addAll(right);
        
        return myList;
        */
        
    }
    
}