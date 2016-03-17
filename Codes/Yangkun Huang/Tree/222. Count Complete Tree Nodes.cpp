  // 左右深度是否相等
  // 相等直接计算
  // 不相等分别递归计算左右子树节点数量 再附加根节点
  int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftDepth = 0, rightDepth= 0;
        for(TreeNode* p=root; p; p=p->left) ++leftDepth;
        for(TreeNode* p=root; p; p=p->right) ++rightDepth;
        if (leftDepth==rightDepth) {
            return (1<< leftDepth) - 1 ;
        }
        else {
            return countNodes(root->left) + countNodes(root->right) + 1 ;
        }
    }