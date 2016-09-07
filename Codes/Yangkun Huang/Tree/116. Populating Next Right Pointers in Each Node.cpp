// method 1 levelOrder traversal
void connect(TreeLinkNode *root) {
	queue<TreeLinkNode *> q;
	if (root)
		q.push(root);
	TreeLinkNode *temp = q.front();
	for (int j = q.size(); !q.empty(); j = q.size()){
		for (int i = 0; i<j; i++){
			if (q.front()->left)
				q.push(q.front()->left);
			if (q.front()->right)
				q.push(q.front()->right);
			q.pop();
			temp->next = i == j - 1 ? nullptr : q.front();
			temp = q.front();
		}
	}
}

// method 2 suppose root has a dummy sibling
void connect(TreeLinkNode *root) {
	connect(root, NULL);
}

void connect(TreeLinkNode *root, TreeLinkNode *sibling) {
	if (root == nullptr)
		return;
	else
		root->next = sibling;
	connect(root->left, root->right);
	if (sibling)
		connect(root->right, sibling->left);
	else
		connect(root->right, nullptr);
}

// method 3
void connect(TreeLinkNode *root) {
	if (!root)
		return;
	while (root->left){
		TreeLinkNode *p = root;
		while (p){
			p->left->next = p->right;
			if (p->next)
				p->right->next = p->next->left;
			p = p->next;
		}
		root = root->left;
	}
}
