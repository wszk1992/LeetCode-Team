    ListNode* rotateRight(ListNode* head, int k) {
        if(head && head->next && k){
            int len=1;
            ListNode *pt=head, *label=head;
            while(pt->next){
                len++;
                pt=pt->next;
            }
            pt->next=label;         // make a cycle at first
            k=k%len;
            ListNode *prev=new ListNode(0);
            prev->next=head;    
            for(int i=0;i<len-k;i++){     // find the correct pos to cut
                head=head->next;
                prev=prev->next;
            }
            prev->next=NULL;
        }
        return head;
    }
