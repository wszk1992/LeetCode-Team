    // O(nlgn) solution
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root=NULL;    // must initialize to NULL otherwise it becomes random value
        if(head){
            ListNode *slow=head, *fast=head, *prev=head;
            if(!fast->next)     // fast should be initialized the same as slow
                return new TreeNode(head->val);
            // ListNode *fast=head->next;
            // if(!fast)
            //     return new TreeNode(head->val);
            // if(!fast->next)
            //     slow=slow->next;
            while(fast && fast->next){
                prev=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            prev->next=NULL;
            root=new TreeNode(slow->val);
            root->left=sortedListToBST(head);
            root->right=sortedListToBST(slow->next);
        }
        return root;
    }
    
    // O(n) solution  
    // how to track positions (unlike array which can use index)
    // recursive - iterative
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *pt=head;
        int count=0;
        while(pt){
            pt=pt->next;
            ++count;
        }
        return aux_func(head, 0, count-1); // possible value of mid is the sub-roots of each level
    }
    
    TreeNode* aux_func(ListNode* &head, int start, int end){
        if(start>end)
            return NULL;
        int mid = start + (end - start) / 2;// same as (start+end)/2, avoids overflow
        TreeNode* tmp=aux_func(head, start, mid-1);
        TreeNode* root=new TreeNode(head->val);
        root->left=tmp;
        head=head->next;    // important since head uses reference to move to next position
        root->right=aux_func(head, mid+1, end);
        return root;
    }
