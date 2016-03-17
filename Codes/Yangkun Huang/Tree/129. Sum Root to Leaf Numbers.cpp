    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
        
    }

    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) 
        return 0;
        if (root->left == nullptr && root->right == nullptr)
        return sum * 10 + root->val;                             // 向上返回到任一节点时，此时的值为经过该节点的所有path的和
        return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val); 
    }