// morris traversal
vector<int> postorderTraversal(TreeNode *root) {
	vector<int> result;
	TreeNode dummy(-1);
	TreeNode *cur, *prev = nullptr;
	std::function < void(const TreeNode*)> visit =
		[&result](const TreeNode *node){
		result.push_back(node->val);
	};
	dummy.left = root;
	cur = &dummy;
	while (cur != nullptr) {
		if (cur->left == nullptr) {
			prev = cur; //------------------------------- prev为cur的parent------------------------------------------------
			cur = cur->right;
		}
		else {
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur)
				node = node->right;
			if (node->right == nullptr) { 
				node->right = cur;
				prev = cur; 
				cur = cur->left;
			}
			else { 
				visit_reverse(cur->left, prev, visit);
				prev->right = nullptr;
				prev = cur;
				cur = cur->right;
			}
		}

	}
	return result;
}
private:
	static void reverse(TreeNode *from, TreeNode *to) {
		TreeNode *x = from, *y = from->right, *z;
		if (from == to) return;
		while (x != to) {
			z = y->right;
			y->right = x;
			x = y;
			y = z;
		}
	}
	static void visit_reverse(TreeNode* from, TreeNode *to,
		std::function< void(const TreeNode*) >& visit) {
		TreeNode *p = to;
		reverse(from, to);
		while (true) {
			visit(p);
			if (p == from)
				break;
			p = p->right;
		}
		reverse(to, from);
	}


// morris
//vector<int> v;
//vector<int> postorderTraversal(TreeNode* root) {
//
//	TreeNode dump(0);
//	dump.left = root;
//	TreeNode *cur = &dump, *prev = NULL;
//	while (cur)
//	{
//		if (cur->left == NULL)
//			cur = cur->right;
//		else
//		{   //------------------------------- prev为cur的前继------------------------------------------------
//			prev = cur->left;
//			while (prev->right != NULL && prev->right != cur)
//				prev = prev->right;
//
//			if (prev->right == NULL)
//			{
//				prev->right = cur;
//				cur = cur->left;
//			}
//			else
//			{
//				printReverse(cur->left, prev);  // call print
//				prev->right = NULL;
//				cur = cur->right;
//			}
//		}
//	}
//	return v;
//
//}
//
//void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
//{
//	if (from == to)
//		return;
//	TreeNode *x = from, *y = from->right, *z;
//	while (true)
//	{
//		z = y->right;
//		y->right = x;
//		x = y;
//		y = z;
//		if (x == to)
//			break;
//	}
//}
//
//void printReverse(TreeNode* from, TreeNode *to) // print the reversed tree nodes 'from' -> 'to'.
//{
//	reverse(from, to);
//
//	TreeNode *p = to;
//	while (true)
//	{
//		v.push_back(p->val);
//		if (p == from)
//			break;
//		p = p->right;
//	}
//
//	reverse(to, from);
//}
    
    // iterative
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> v;
    //     stack<TreeNode*> sta;
    //     if(root)
    //     sta.push(root);
    //     while(!sta.empty())
    //     {
    //         TreeNode* p=sta.top();
      
    //         if(p->right)
    //         sta.push(p->right);
    //         if(p->left)
    //         sta.push(p->left);
            
    //     }
    //     return v;
    // }
