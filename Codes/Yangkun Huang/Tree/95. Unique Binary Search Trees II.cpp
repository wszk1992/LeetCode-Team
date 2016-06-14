 vector<TreeNode *> generateTrees(int n) {
	 if (n == 0)
	 {
		 vector<TreeNode *> v;
		 return v;
	 }
	 return generate(1, n);
 }
 vector<TreeNode *> generate(int start, int end) {
	 vector<TreeNode*> subTree;
	 if (start > end) {
		 subTree.push_back(nullptr);
		 return subTree;
	 }
	 for (int k = start; k <= end; k++) {   // 一共有n种划分
		 vector<TreeNode*> leftSubs = generate(start, k - 1);  // 左子树的所有情况
		 vector<TreeNode*> rightSubs = generate(k + 1, end);   // 右子树的所有情况
		 for (auto i : leftSubs) {                             // 左右子树相乘
			 for (auto j : rightSubs) {
				 TreeNode *node = new TreeNode(k);
				 node->left = i;
				 node->right = j;
				 subTree.push_back(node);
			 }
		 }
	 }
	 return subTree;
 }