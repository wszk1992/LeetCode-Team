    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vv;
        vector<int> vec;
        find_sum(vv,vec,root,sum);
        return vv;
    }
    
    void find_sum( vector<vector<int>> &vv, vector<int> &v,TreeNode* root, int sum){
        if(!root)
        return ;     
        v.push_back(root->val);                              // store path value
        if (root->left == nullptr && root->right == nullptr) // leaf
            if(sum == root->val)
               vv.push_back(v);
        find_sum(vv,v,root->left,sum-root->val);
        find_sum(vv,v,root->right,sum-root->val);
        v.pop_back();                                       // delete current value and return prior 
    }