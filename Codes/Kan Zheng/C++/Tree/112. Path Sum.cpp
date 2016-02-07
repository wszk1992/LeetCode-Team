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
    //can't figure out how to handle [] 0
    // bool hasPathSum(TreeNode* root, int sum) {
    //     if(root==NULL&&sum!=0)
    //         return false;
    //     else if (root==NULL&&sum==0)
    //         return true;
    //     else if(hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val))
    //         return true;
    // }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        else if (root->left==NULL&&root->right==NULL){
            if(root->val==sum)
                return true;
            else
                return false;
        }
        else if (root->left==NULL&&root->right!=NULL)
            return hasPathSum(root->right, sum-root->val);
        else if (root->left!=NULL&&root->right==NULL)
            return hasPathSum(root->left, sum-root->val);
        else
            return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};