  // ��������Ƿ����
  // ���ֱ�Ӽ���
  // ����ȷֱ�ݹ�������������ڵ����� �ٸ��Ӹ��ڵ�
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