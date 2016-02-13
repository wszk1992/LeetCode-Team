
// recursive
vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int>> result;
	traverse(root, 1, result);
	return result;
}
void traverse(TreeNode *root, size_t level, vector<vector<int>> &result) {
	if (!root) return;
	if (level > result.size())
		result.push_back(vector<int>());
	result[level - 1].push_back(root->val);
	traverse(root->left, level + 1, result);
	traverse(root->right, level + 1, result);
}


// iterative
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            vector<int> level;                 // store nodes at each level
            for(int i=0;i<q.size();i++)   
            {
                level.push_back(q.front()->val);
                q.push(q.front());
                q.pop();
            }
            for(int i=0,j=q.size();i<j;i++) //循环过程中q.size()会改变
            {
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);
                q.pop();
            }
            v.push_back(level);
        }
        return v;
    }