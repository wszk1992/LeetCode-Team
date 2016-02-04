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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        // solution 1: just like problem 102, plus--- Collections.reverse()
        
        // solution 2: preorder traversal
        
        
        List<List<Integer>> myList = new ArrayList ();
        if(root==null)
            return myList;
            
        traversal(myList,root,0);
        
        Collections.reverse(myList);
        
        return myList;
        
    }
    public void traversal(List<List<Integer>> myList, TreeNode myNode, int dep){
        
       // if(myNode == null) return;
        
        if(dep==myList.size()){
            // first node of each level, create new levList
            List<Integer> levList = new ArrayList<Integer>();
            myList.add(levList);
            
        }
        // add val of myNode to specific levList
        (myList.get(dep)).add(myNode.val);
        
       if(myNode.left!=null)  traversal(myList,myNode.left,dep+1);
       if(myNode.right!=null) traversal(myList,myNode.right,dep+1);
    }
    
    
}