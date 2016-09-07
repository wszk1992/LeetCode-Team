    // solution 1 merge two lists
    ListNode* partition(ListNode* head, int x) {
        ListNode *p1 = new ListNode(0), *p2 = new ListNode(0), *copy1=p1, *copy2=p2;
        while (head) {
            if (head->val < x)
               p1 = p1->next = head;
            else
                p2 = p2->next = head;
            head = head->next;
        }
        p2->next = NULL;
        p1->next = copy2->next;
        return copy1->next;
    }
    
    // solution 2 pick up those smaller nodes
    ListNode* partition(ListNode* head, int x) {
        ListNode *greater=new ListNode(0), *smaller=new ListNode(0), *res=smaller, *pt=head, *copy=greater;
        greater->next=head;
        while(pt){
            if(pt->val<x){
                smaller->next=pt;
                smaller=smaller->next;
                greater->next=pt->next;
                pt=pt->next;
                smaller->next=NULL;
            }
            else{
                greater=greater->next;
                pt=pt->next;
            }
        }
        smaller->next=copy->next;
        return res->next;
    }    
    
    

