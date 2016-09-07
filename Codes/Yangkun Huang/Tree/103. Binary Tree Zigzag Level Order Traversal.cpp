
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int>> v;
	queue<TreeNode*> q;
	if (root)
		q.push(root);
	bool tag = false;
	while (!q.empty()){
		vector<int> result;
		for (int i = 0, j = q.size(); i<j; i++){
			result.push_back(q.front()->val);
			if (q.front()->left)
				q.push(q.front()->left);
			if (q.front()->right)
				q.push(q.front()->right);
			q.pop();
		}
		if (tag)
			reverse(result.begin(), result.end());
		v.push_back(result);
		tag=!tag;
	}
	return v;
}
