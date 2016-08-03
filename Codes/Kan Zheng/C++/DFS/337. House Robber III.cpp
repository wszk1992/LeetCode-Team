class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    //return res[0] = rob with root, res[1] = rob without root
    vector<int> dfs(TreeNode* root) {
        if(root == NULL) {
            return vector<int>(2, 0);
        }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> res(2, 0);
        res[0] = root->val + left[1] + right[1];
        res[1] = max(left[0], left[1]) + max(right[0],right[1]);
        return res;
    }
};