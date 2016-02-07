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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
        {
            int maxleft = maxDepth(root->left);
            int maxright = maxDepth(root->right);
            return (maxleft>maxright?maxleft:maxright)+1;
        }
    }
};