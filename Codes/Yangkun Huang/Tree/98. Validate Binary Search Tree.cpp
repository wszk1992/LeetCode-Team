  bool isValidBST(TreeNode* root) {
        int temp=INT_MIN;          // 递归返回时传递前继节点的值 
        bool tag=false;            // special condition for root node
        return inorder(root, &temp, &tag);
    }
    bool inorder(TreeNode* root,int* temp, bool* tag)
    {
        if(root)
        {
            if(!inorder(root->left,temp,tag))
            return false;
            if(*tag)
            if(*temp>=root->val) 
            return false;
            if(!*tag)
            *tag=true;
            *temp=root->val;
            if(!inorder(root->right,temp,tag))
            return false;
        }
        return true;
    }
    
    
 // worse solution  
    // stack<int> s;         // inorder放入栈中
    // bool isValidBST(TreeNode* root) {     
    //   inorder(root);
    //     for(int i=0,j=0,k=s.size();i<k;i++)  
    //     {
    //         j=s.top();
    //         s.pop();
    //         if(!s.empty()&&j<=s.top())
    //         return false;
    //     }
    //     return true;
    // }
    // void inorder(TreeNode* root)
    // {
    //     if(root)
    //     {
    //         inorder(root->left);
    //         s.push(root->val);
    //         inorder(root->right);
    //     }
    // }