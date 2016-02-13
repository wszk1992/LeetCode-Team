/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vecvec;
        vector<int> vec;
        if(root==NULL)
            return vecvec;
        //1:conbine left and right
        vecvec = conbine_vv(levelOrder(root->left),levelOrder(root->right));
        //2:add it self
        vec.push_back(root->val);
        vecvec.insert(vecvec.begin(),vec);
        //return vecvec
        return vecvec;
    }
    vector<vector<int>> conbine_vv(vector<vector<int>> left,vector<vector<int>> right)
    {
        vector<vector<int>> vec;
        if(left.empty())
            return right;
        else if(right.empty())
            return left;
        bool useleft;
        if(left.size()>right.size())
            {useleft=true;vec=left;}
        else
            {useleft=false;vec=right;}
        int i,j;
        for(i=0,j=0;i<left.size()&&j<right.size();i++,j++)
        {
            if(useleft)
                vec[i]=conbine_v(left[i],right[j]);
            else
                vec[j]=conbine_v(left[i],right[j]);
        }
        return vec;
    }
    //conbine a and b
    vector<int> conbine_v(vector<int> a,vector<int> b)
    {
        vector<int> vec=a;
        for(int i=0;i<b.size();i++)
            vec.push_back(b[i]);
        return vec;
    }
};

//use queue
