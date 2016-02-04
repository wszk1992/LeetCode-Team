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
    public List<List<Integer>> levelOrder(TreeNode root) {
      
        // someone's solution: very good-----try something new next question
        ArrayList<List<Integer>> finalList = new ArrayList<List<Integer>> ();
        LinkedList <TreeNode> myQue = new LinkedList <TreeNode>(); // used to be integer
        if(root==null)
            return finalList;
        myQue.add(root);
        while(myQue.size()>0){
            ArrayList<Integer> temList = new ArrayList<Integer>();
            int size =myQue.size();
            for(int i=0;i<size;i++){  //----------> myQue.size() change over time!!!
                TreeNode myNode = myQue.poll();
                
                temList.add(myNode.val);
                if(myNode.left!=null) myQue.add(myNode.left);
                if(myNode.right!=null) myQue.add(myNode.right);
                
            }
            
            finalList.add(temList);
        }
        return finalList;
        
        
        
        
        
    }
}