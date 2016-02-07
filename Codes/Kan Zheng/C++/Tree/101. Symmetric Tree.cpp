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
    //BUG: iteratively
    // bool isSymmetric(TreeNode* root) {
    //     if(root==NULL)
    //         return true;
    //     vector<TreeNode*> vectree;
    //     vector<TreeNode*> new_vectree;
    //     TreeNode* leftNode;
    //     TreeNode* rightNode;
    //     bool allisnull=false;
    //     vectree.push_back(root);
    //     while(!allisnull)
    //     {
    //         allisnull=true;
    //         for(int i=0;i<vectree.size();i++)
    //         {
    //             if(vectree[i]==NULL)
    //                 leftNode=rightNode=NULL;
    //             else
    //             {
    //                 leftNode=vectree[i]->left;
    //                 rightNode=vectree[i]->right;
    //             }
    //             new_vectree.push_back(leftNode);
    //             new_vectree.push_back(rightNode);
    //             if(leftNode!=NULL||rightNode!=NULL)
    //                 allisnull=false;
    //         }
    //         vectree = new_vectree;
    //         if(!symInLine(vectree))
    //         {
    //             //cout<<"sysinline false"<<endl;
    //             return false;
    //         }
    //         new_vectree.clear();
            
    //     }
    //     return true;
    // }
    // bool symInLine(vector<TreeNode*> vec)
    // {
    //     int i,j;
    //     for(i=0,j=vec.size()-1;i<=j;i++,j--)
    //     {
    //         if(vec[i]==NULL&&vec[j]==NULL)
    //             continue;
    //         else if((vec[i]==NULL&&vec[j]!=NULL)||vec[i]!=NULL&&vec[j]==NULL)
    //             return false;
    //         else if(vec[i]->val!=vec[j]->val)
    //             return false;
    //     }
    //     return true;
    // }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else
            return twoIsSym(root->left,root->right);
    }
    
    bool twoIsSym(TreeNode* a,TreeNode*b)
    {
        if(a==NULL&&b==NULL)
            return true;
        else if ((a==NULL&&b!=NULL)||(a!=NULL&&b==NULL))
            return false;
        else
            return (a->val==b->val)&&twoIsSym(a->left,b->right)&&twoIsSym(a->right,b->left);
    }
    
};