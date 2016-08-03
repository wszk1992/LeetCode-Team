/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //recursive
        if(root&&root->left)
        {
            connect(root->left);
            connect(root->right);
            TreeLinkNode* nodeleft;
            TreeLinkNode* noderight;
            root->left->next = root->right;
            nodeleft = root->left->right;
            noderight = root->right;
            while(nodeleft)
            {
                nodeleft->next = noderight->left;
                nodeleft = nodeleft->right;
                noderight = noderight->left;
            }
        }
    }
};