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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else
            return twoIsSym(root->left,root->right);
    }
    
    bool twoIsSym(TreeNode* a,TreeNode*b)
    {
        if(a==NULL&&b==NULL)
            return true;
        else if ((a==NULL&&b!=NULL)||(a!=NULL&&b==NULL))
            return false;
        else
            return (a->val==b->val)&&twoIsSym(a->left,b->right)&&twoIsSym(a->right,b->left);
    }
    
};
//iteratively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            TreeNode* n1 = q.front();
            q.pop();
            TreeNode* n2 = q.front();
            q.pop();
            if(!n1 && !n2) {
                continue;
            }else if(!n1 || !n2 || n1->val != n2->val) {
                return false;
            }else {
                q.push(n1->left);
                q.push(n2->right);
                q.push(n1->right);
                q.push(n2->left);
            }
        }
        return true;
    }
    
};