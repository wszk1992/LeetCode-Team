vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            vector<int> vi;
            for(int i=0;i<q.size();i++)   
            {
                vi.push_back(q.front()->val);
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
            v.push_back(vi);
        }
        for(int i=v.size()-1;i>=0;i--)
        vv.push_back(v[i]);
        return vv;
    }