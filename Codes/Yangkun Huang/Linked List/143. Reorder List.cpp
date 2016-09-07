    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)       // skip some cases
            return;
        ListNode *curr, *prev;
        ListNode *slow=head, *fast=head;        
        while(fast && fast->next){              // find middle pos and tail pos, divide the list into two sublist
            prev=slow;  
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=slow->next;
        prev->next->next=NULL;
        prev=slow, curr= slow->next;
        while(curr){                            // reverse the second sublist
            ListNode *tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;           
        }
        slow->next=NULL, curr=head;
        while(curr && prev){                    // merge two sublists
            ListNode *tmp1=curr->next, *tmp2=prev->next;
            curr->next=prev;
            prev->next=tmp1;
            curr=tmp1;
            prev=tmp2;
        }
    }
