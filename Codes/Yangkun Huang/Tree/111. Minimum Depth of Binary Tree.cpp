  int minDepth(const TreeNode *root) {
      return minDepth(root, false);
  }
  static int minDepth(const TreeNode *root, bool hasbrother) {
      if (!root) 
        return hasbrother ? INT_MAX : 0;
      return 1 + min(minDepth(root->left, root->right != NULL), minDepth(root->right, root->left != NULL));
  }
