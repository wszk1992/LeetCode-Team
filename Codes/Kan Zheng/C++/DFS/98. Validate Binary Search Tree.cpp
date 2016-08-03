/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        return isValidBST(root->left)&&isValidBST(root->right)&&midBiggerThanLeft(root)&&midSmallerThanright(root);
    }
    
    bool midBiggerThanLeft(TreeNode* root)
    {
        TreeNode* node=root->left;
        if(node==NULL)
            return true;
        while(node->right)
            node=node->right;
        return root->val>node->val;
    }
    
    bool midSmallerThanright(TreeNode* root)
    {
        TreeNode* node=root->right;
        if(node==NULL)
            return true;
        while(node->left)
            node=node->left;
        return root->val<node->val;
    }
};