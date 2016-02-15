    ListNode* insertionSortList(ListNode* head) { 
            if (head == NULL || head->next == NULL) // form a sorted sub-list
        return head;                                // insert each of the remained nodes into the sub-list

    ListNode *p = head->next;        // 数组插入需要移动全部后续元素
    head->next = NULL;

    while (p != NULL)               
                                    
    {
        ListNode *pNext = p->next;    /*store the next node to be insert*/
        ListNode *q = head;

        if (p->val < q->val)    /*node p should be the new head*/
        {
            p->next = q;
            head = p;
        }
        else 
        {
            while (q != NULL && q->next != NULL && q->next->val <= p->val)
                q = q->next;
            p->next = q->next;
            q->next = p;
        }

        p = pNext;
    }
    return head;

        // Bubble Sort
        // int temp;
        // for(ListNode *p=head;p->next!=NULL;p=p->next)
        // for(ListNode *q=head;q->next!=NULL;q=q->next)
        // if(q->val>q->next->val)
        // {
        //     temp=q->val;
        //     q->val=q->next->val;
        //     q->next->val=temp;
        // }
        // }
        // return head;
    }