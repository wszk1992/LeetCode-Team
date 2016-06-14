   // method 1 time O(n) space O(logn)
void flatten(TreeNode *root) {   // �����¿�ʼ
	if (root == nullptr)
		return;
	flatten(root->left);
	flatten(root->right);
	if (root->left != nullptr)   // �ֱ���������������ٿ�ʼ�ϲ�   
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
   void flatten(TreeNode *root) {   // �����¿�ʼ
	   flatten(root, NULL);
   }

   TreeNode *flatten(TreeNode *root, TreeNode *tail) {    
	   if (root == NULL) 
		   return tail;
	   root->right = flatten(root->left, flatten(root->right, tail)); // ��벿��flatten(right,NULL) return right
	   root->left = NULL;                                             // ǰ�벿��flatten(left->left,right) return right
	   return root;
   }