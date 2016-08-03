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
    vector<int> rightSideView(TreeNode* root) {
        //recursive
        /*
        vector<int> vec;
        if(!root)
            return vec;
        vector<int> left=rightSideView(root->left);
        vector<int> right=rightSideView(root->right);
        if(right.size()>=left.size())
        {
            vec = right;
        }
        else
        {
            vec = left;
            for(int i=0;i<right.size();i++)
                vec[i]=right[i];
        }
        vec.insert(vec.begin(),root->val);
        return vec;
        */
        
        //iterater

        vector<TreeNode*> vec_old;
        vector<TreeNode*> vec_new;
        vector<int> vec;
        if(!root)
            return vec;
        vec_old.push_back(root);
        while(!vec_old.empty())
        {
            vec.push_back(vec_old.back()->val);
            for(int i=0;i<vec_old.size();i++)
            {
                if(vec_old[i]->left!=NULL)
                    vec_new.push_back(vec_old[i]->left);
                if(vec_old[i]->right!=NULL)
                    vec_new.push_back(vec_old[i]->right);
            }
            vec_old = vec_new;
            vec_new.clear();
        }
        return vec;
    }
};