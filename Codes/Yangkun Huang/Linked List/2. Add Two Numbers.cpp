    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* res=new ListNode(0), *pt=res;
        while(l1 && l2){
            int curr=l1->val+l2->val+carry;
            pt->next=new ListNode(curr%10);
            carry= curr>=10 ? 1:0;
            pt=pt->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            pt->next=new ListNode((l1->val+carry)%10);
            carry= (l1->val+carry)>=10 ? 1:0;
            l1=l1->next;
            pt=pt->next;
        }
        while(l2){
            pt->next=new ListNode((l2->val+carry)%10);
            carry= (l2->val+carry)>=10 ? 1:0;
            l2=l2->next;
            pt=pt->next;
        }
        if(carry)
            pt->next=new ListNode(carry);
        return res->next;
    }
