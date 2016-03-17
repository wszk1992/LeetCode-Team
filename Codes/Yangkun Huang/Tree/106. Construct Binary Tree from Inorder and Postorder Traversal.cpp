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
    while (true)  // 每次循环都是以st.top()构建左右子树
    {
        if (st.top()->val == inorder[j]) // 判断根节点的inorder前继是根节点还是在右子树中(是否有右子树)
        {
            node = st.top();
            st.pop();
            j--;
            if (j < 0) // check if it reachs the head of inorder
               break; 
            if (st.empty() || st.top()->val != inorder[j])  // 判断inorder前继是亲节点(后面用了替换)还是在左子树中(是否有左子树)
            {   // next inorder is left child
                node->left = new TreeNode(postorder[i]); // 左孩子始终在序列前半部分，所以此时i一定是停在左孩子上
                i--;                                     // i--指向前一个左孩子或自己的左孩子
                st.push(node->left);                     // 放入stack中，相当于替换掉当前的node，下一步循环可以直接判断亲节点是不是前继
            }
        }
        else  // 构建右子树
        {
            node = new TreeNode(postorder[i]);
            i--;
            st.top()->right = node;
            st.push(node);
        }
    }
    return root;
}