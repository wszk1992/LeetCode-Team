    // 12ms
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode *record=new ListNode(0), *move=head, *sentinel=record;
        record->next=head;
        while(record->next){
            move=record->next;
            if(move->next && move->val==move->next->val){
                while(move->next && move->val==move->next->val)
                    move=move->next;
                record->next=move->next;
            }
            else
                record=record->next;
        }
        return sentinel->next;
    }
    
    // 8ms
     ListNode* deleteDuplicates(ListNode* head) {
        if( !head ) 
            return NULL;
        ListNode* p = new ListNode(head->val-1), *ptr = p, *pre = p;
        while( head ) {
            if( pre->val != head->val && (!head->next || head->next->val != head->val )) {
                ptr->next = head;
                ptr = ptr->next;
            }
            pre = head;
            head = head->next;
        }
        ptr->next = NULL; // delete duplicates at the end of list
        return p->next;
    }
