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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root==NULL)
            return vec;
        stack<TreeNode*> s;
        TreeNode* cur_node=root;
        while(1)
        {
            if(cur_node->left==NULL)
            {    
                vec.push_back(cur_node->val);
                while(cur_node->right==NULL)
                {
                    if(s.empty())
                        return vec;
                    cur_node = s.top();
                    vec.push_back(cur_node->val);
                    s.pop();
                }
                cur_node = cur_node->right;
            }
            else
            {
                s.push(cur_node);
                cur_node = cur_node->left;
            }
        }
        
    }
};