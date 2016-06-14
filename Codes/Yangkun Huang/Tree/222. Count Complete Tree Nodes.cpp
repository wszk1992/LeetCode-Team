  // method 1
  // ��������Ƿ����
  // ���ֱ�Ӽ���
  // ����ȷֱ�ݹ�������������ڵ����� �ٸ��Ӹ��ڵ�
  int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftDepth = 0, rightDepth= 0;
		for(TreeNode* p=root; p; p=p->left) 
			++leftDepth;                          // ÿ���ڵ㶼�ظ��ۼ�,�˷�
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