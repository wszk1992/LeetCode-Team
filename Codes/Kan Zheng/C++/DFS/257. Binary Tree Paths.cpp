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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        dfs(res, s, root);
        return res;
    }
    
    void dfs(vector<string>& res, string& s, TreeNode* root) {
        if(!root) {
            return;
        }
        string str = to_string(root->val);
        if(!root->left && !root->right) {
            s += str;
            res.push_back(s);
            s.erase(s.size() - str.size());
        }else {
            s += str + "->";
            dfs(res, s, root->left);
            dfs(res, s, root->right);
            s.erase(s.size() - str.size() - 2);
        }
    }
};