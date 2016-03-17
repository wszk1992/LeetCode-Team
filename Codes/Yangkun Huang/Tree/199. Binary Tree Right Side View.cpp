 // rightmost node in level-order traversal 
 vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            result.push_back(q.back()->val);
            for(int i=0,j=q.size();i<j;i++) 
            {
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);
                q.pop();
            }
        }
        return result;
    }