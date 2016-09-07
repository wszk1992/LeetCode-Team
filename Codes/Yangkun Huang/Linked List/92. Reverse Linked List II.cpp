    // it is important to skip some cases in linked list problems
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n<2 || m==n)     // skip these cases
            return head;
        int headPos=1, tailPos=1;
        ListNode *newHead=new ListNode(0), *newTail=head;   // set up a dummy node to deal with m==1 case
        newHead->next=head;
        while(tailPos++<n){ // first find the sublist which need to be reversed
            if(headPos++<m)
                newHead=newHead->next;
            newTail=newTail->next;
        }
        ListNode *first=newHead, *second=newTail->next;
        newHead=newHead->next;
        for(auto qt=newHead, pt=newHead->next;pt!=second;){ // reverse the sublist
            ListNode *tmp=pt->next;
            pt->next=qt;
            qt=pt;
            pt=tmp;
        }
        first->next=newTail;    // connect to original list
        newHead->next=second;
        return m==1 ? first->next : head;
    }
