  // method 1
  // 左右深度是否相等
  // 相等直接计算
  // 不相等分别递归计算左右子树节点数量 再附加根节点
  int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftDepth = 0, rightDepth= 0;
		for(TreeNode* p=root; p; p=p->left) 
			++leftDepth;                          // 每个节点都重复累加,浪费
        for(TreeNode* p=root; p; p=p->right) 
			++rightDepth;
        if (leftDepth==rightDepth) 
			return (1<< leftDepth) - 1 ;
		else
			return countNodes(root->left) + countNodes(root->right) + 1 ;
    }

  // mehtod 2
  int countNodes(TreeNode* root) {
	  if (!root) 
		  return 0;
	  int num = 1;
	  TreeNode *curR(root->left), *curL(root->left);
	  while (curR) // curR is the rightmost edge, which has a height equal to or less than the leftmost edge
	  {
		  curL = curL->left;
		  curR = curR->right;
		  num = num << 1;
	  }
	  return  num + ((!curL) ? countNodes(root->right) : countNodes(root->left));
  }