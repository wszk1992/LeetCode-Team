   // method 1 time O(n) space O(logn)
void flatten(TreeNode *root) {   // 从左下开始
	if (root == nullptr)
		return;
	flatten(root->left);
	flatten(root->right);
	if (root->left != nullptr)   // 分别处理好左右子树后再开始合并   
	{
		TreeNode *p = root->left;
		while (p->right) 
			p = p->right;
		p->right = root->right;
		root->right = root->left;
		root->left = nullptr;
	}
}


   // method 2 time O(n) space O(logn)
   void flatten(TreeNode *root) {   // 从右下开始
	   flatten(root, NULL);
   }

   TreeNode *flatten(TreeNode *root, TreeNode *tail) {    
	   if (root == NULL) 
		   return tail;
	   root->right = flatten(root->left, flatten(root->right, tail)); // 后半部分flatten(right,NULL) return right
	   root->left = NULL;                                             // 前半部分flatten(left->left,right) return right
	   return root;
   }