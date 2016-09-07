
    
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
