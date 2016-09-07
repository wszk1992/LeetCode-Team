vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            vector<int> vi;
            for(int i=0;i<q.size();i++){
                vi.push_back(q.front()->val);
                q.push(q.front());
                q.pop();
            }
            for(int i=0,j=q.size();i<j;i++){//Ñ­»·¹ý³ÌÖÐq.size()»á¸Ä±ä
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);
                q.pop();
            }
            v.push_back(vi);
        }
        return v;
    }
