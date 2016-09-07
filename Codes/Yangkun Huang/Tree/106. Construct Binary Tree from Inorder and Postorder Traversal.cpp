 // method 1 
 // postorder最后一个为根节点，找到根节点在inorder中的位置
 // inorder中分别找到左子树和右子树的序列
 // postorder中找到左右子树的序列
 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0 || postorder.size() == 0)
        return 0;
    TreeNode* root = new TreeNode(postorder.back());
    if (postorder.size() == 1)
        return root;

    stack<TreeNode*> st;
    st.push(root);
    int i = postorder.size() - 2;
    int j = inorder.size() - 1;
    TreeNode* node;
    while (true){
        if (st.top()->val == inorder[j]){ // 判断根节点的inorder前继是根节点还是在右子树中(直到最右下处)
            node = st.top();
            st.pop();
            j--;
            if (j < 0) // check if it reachs the head of inorder
               break; 
            if (st.empty() || st.top()->val != inorder[j]){  // 判断inorder前继是亲节点还是在左子树中(是否有左子树)
                // inorder前继在左子树中
                node->left = new TreeNode(postorder[i]); // 左孩子始终在序列前半部分，所以此时i一定是停在左孩子上
                i--;                                     // i--指向前一个左孩子或自己的左孩子
                st.push(node->left);                     // 放入stack中，相当于替换掉当前node，下一步循环可以判断亲节点是不是前继
            }
        }
        else{  // 构建右子树
            node = new TreeNode(postorder[i]);
            i--;
            st.top()->right = node;
            st.push(node);
        }
    }
    return root;
}


 // method 2

 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	 return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
 }
 TreeNode* buildTree(vector<int>::iterator in_fir, vector<int>::iterator in_las, vector<int>::iterator post_fir, vector<int>::iterator post_las){
	 if (in_fir == in_las || post_fir == post_las)
		 return nullptr;

	 TreeNode* root = new TreeNode(*prev(post_las));

	 vector<int>::iterator fir_pos = find(in_fir, in_las, *prev(post_las));

	 int l_size = distance(in_fir, fir_pos);//fir_pos-in_fir

	 root->left = buildTree(in_fir, next(in_fir, l_size), post_fir, next(post_fir, l_size));
	 root->right = buildTree(next(fir_pos), in_las, next(post_fir, l_size), prev(post_las));

	 return root;
 }
