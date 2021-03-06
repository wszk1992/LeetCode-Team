/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//recursive
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return root == NULL ||
	 (abs(getDepth(root->left) - getDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
    
    int getDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
        {
            int leftdepth=getDepth(root->left);
            int rightdepth=getDepth(root->right);
            return (leftdepth>rightdepth?leftdepth:rightdepth)+1;
        }
    }
};