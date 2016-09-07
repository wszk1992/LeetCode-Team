    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return nullptr;
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(slow==head)
            return head;
        fast=head;
        while(slow){
            slow=slow->next;
            fast=fast->next;
            if(fast==slow)
                return fast;
        }
        return nullptr;
    }
