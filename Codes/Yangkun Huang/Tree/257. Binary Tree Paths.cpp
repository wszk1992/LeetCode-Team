 vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(!root)
        return v;
        string s;
        path(root,false,s,v);
        return v;
    }
    void path(TreeNode* root, bool hasbrother, string &s, vector<string> &v)
    {
        if(!root&&!hasbrother)     
        {
            s.erase(s.size()-2,2); //ȥ���������->
            v.push_back(s);
        }
        if(root)
        {
            string t=s+to_string(root->val)+"->"; // preorder traversal
            path(root->left,root->right!=NULL,t,v);// hasbrother�ж��Һ��ӽڵ��Ƿ�ΪNULL
            path(root->right,true,t,v);            // �Һ��Ӳ����ظ��ж�
        }
    }
   