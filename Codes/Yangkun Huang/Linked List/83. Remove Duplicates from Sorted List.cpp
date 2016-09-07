    ListNode* deleteDuplicates(ListNode* head) {
         if(head){
             ListNode *p=head;
             while(p->next)
                p->val==p->next->val ? p->next=p->next->next : p=p->next;
         }
         return head;
    }
