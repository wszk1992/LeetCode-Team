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
    while (true)  // ÿ��ѭ��������st.top()������������
    {
        if (st.top()->val == inorder[j]) // �жϸ��ڵ��inorderǰ���Ǹ��ڵ㻹������������(�Ƿ���������)
        {
            node = st.top();
            st.pop();
            j--;
            if (j < 0) // check if it reachs the head of inorder
               break; 
            if (st.empty() || st.top()->val != inorder[j])  // �ж�inorderǰ�����׽ڵ�(���������滻)��������������(�Ƿ���������)
            {   // next inorder is left child
                node->left = new TreeNode(postorder[i]); // ����ʼ��������ǰ�벿�֣����Դ�ʱiһ����ͣ��������
                i--;                                     // i--ָ��ǰһ�����ӻ��Լ�������
                st.push(node->left);                     // ����stack�У��൱���滻����ǰ��node����һ��ѭ������ֱ���ж��׽ڵ��ǲ���ǰ��
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