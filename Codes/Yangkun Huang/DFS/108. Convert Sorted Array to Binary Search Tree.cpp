    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // need to write a auxiliary recursive function, since array cannot be separate into two sub array like linked list
        if(nums.empty())
            return nullptr;
        return aux_func(nums.begin(), nums.end()-1);
    }
    
    TreeNode* aux_func(vector<int>::iterator start, vector<int>::iterator end){
        TreeNode *root=NULL;
        // how to determine whether it is an empty array or not
        if(start<=end){
            if(start==end)
                return new TreeNode(*start);
            auto mid=start+(end-start)/2;
            root=new TreeNode(*mid);
            root->left=aux_func(start, mid-1);
            root->right=aux_func(mid+1, end);
        }
        return root;
    }
