    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !k)
            return head;
        ListNode *prehead=new ListNode(0), *pt=head, *res=prehead;
        prehead->next=head;
        int count=1;
        while(pt=pt->next)  // equal to while(pt->next!=NULL)
            count++;
        for(int i=count/k;head && i>0; i--){
            int num=k;
            while(num>1){
                ListNode *nex=head->next;
                head->next=nex->next;
                nex->next=prehead->next;
                prehead->next=nex;
                num--;
            }
            prehead=head;
            head=head->next;
        }
        return res->next;
    }
    
    // more concise solution
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next) 
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
    }
