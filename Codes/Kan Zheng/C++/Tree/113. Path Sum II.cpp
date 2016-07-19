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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vecvec;
        if(root==NULL)
            return vecvec;
        else if(root->left==NULL&&root->right==NULL)
            if(root->val==sum)
                return vector<vector<int>>(1,vector<int>(1,root->val));
            else
                return vecvec;
        vecvec = mixTwoVec(pathSum(root->left,sum-root->val),pathSum(root->right,sum-root->val));
        addSelf(vecvec,root->val);
        return vecvec;
    }
    vector<vector<int>> mixTwoVec(vector<vector<int>> vecvec1,vector<vector<int>> vecvec2)
    {
        vector<vector<int>> vecvec=vecvec1;
        for(int i=0;i<vecvec2.size();i++)
            vecvec.push_back(vecvec2[i]);
        return vecvec;
    }
    void addSelf(vector<vector<int>>& vecvec,int val)
    {
        for(int i=0;i<vecvec.size();i++)
            vecvec[i].insert(vecvec[i].begin(),val);
    }
    
};
