  bool isValidBST(TreeNode* root) {
        int pre_node=INT_MIN;          // �ݹ鷵��ʱ����ǰ�̽ڵ��ֵ 
		bool isRoot = true;            // special condition for root node
		return inorder(root, &pre_node, &isRoot);
  }
  bool inorder(TreeNode* root, int* pre_node, bool* isRoot)
  {
	  if (root)
	  {
		  if (!inorder(root->left, pre_node, isRoot))
			  return false;
		  if (!*isRoot)
		  {
			  if (*pre_node >= root->val)   // if - else�����
				  return false;
		  }
		  else
			  *isRoot = false;
		  *pre_node = root->val;
		  if (!inorder(root->right, pre_node, isRoot))
			  return false;
	  }
	  return true;;
    }
    
    
 // worse solution  
    // stack<int> s;         // inorder����ջ��
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