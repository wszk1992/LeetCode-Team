TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
            invertTree(root->left);  // postorder traversal
            invertTree(root->right);
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        return root;
    }