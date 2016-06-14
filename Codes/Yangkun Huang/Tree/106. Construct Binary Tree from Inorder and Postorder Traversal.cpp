 // method 1 
 // postorder���һ��Ϊ���ڵ㣬�ҵ����ڵ���inorder�е�λ��
 // inorder�зֱ��ҵ���������������������
 // postorder���ҵ���������������
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
    while (true)
    {
        if (st.top()->val == inorder[j]) // �жϸ��ڵ��inorderǰ���Ǹ��ڵ㻹������������(ֱ�������´�)
        {
            node = st.top();
            st.pop();
            j--;
            if (j < 0) // check if it reachs the head of inorder
               break; 
            if (st.empty() || st.top()->val != inorder[j])  // �ж�inorderǰ�����׽ڵ㻹������������(�Ƿ���������)
            {   // inorderǰ������������
                node->left = new TreeNode(postorder[i]); // ����ʼ��������ǰ�벿�֣����Դ�ʱiһ����ͣ��������
                i--;                                     // i--ָ��ǰһ�����ӻ��Լ�������
                st.push(node->left);                     // ����stack�У��൱���滻����ǰnode����һ��ѭ�������ж��׽ڵ��ǲ���ǰ��
            }
        }
        else  // ����������
        {
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
 TreeNode* buildTree(vector<int>::iterator in_fir, vector<int>::iterator in_las, vector<int>::iterator post_fir, vector<int>::iterator post_las)
 {
	 if (in_fir == in_las || post_fir == post_las)
		 return nullptr;

	 TreeNode* root = new TreeNode(*prev(post_las));

	 vector<int>::iterator fir_pos = find(in_fir, in_las, *prev(post_las));

	 int l_size = distance(in_fir, fir_pos);//fir_pos-in_fir

	 root->left = buildTree(in_fir, next(in_fir, l_size), post_fir, next(post_fir, l_size));
	 root->right = buildTree(next(fir_pos), in_las, next(post_fir, l_size), prev(post_las));

	 return root;
 }