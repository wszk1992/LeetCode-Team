    // iterative solution
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead, *l1, *l2;
        if (head == NULL) 
            return NULL;
    
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->random;
            l1->random = l2;        // L1->random stores the shadow node of L1, L1->next remains
        }
        
        newHead = head->random;
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : NULL;    // find node in L1 and connect its shadow node to L2
        }
        
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l1->random = l2->next;          // restore L1->random
            l2->next = l1->next ? l1->next->random : NULL;
        }
    
        return newHead;
    }

    // recursive solution with hashmap
    unordered_map<RandomListNode*, RandomListNode*> hmap;

    RandomListNode *copyRandomList(RandomListNode *head) {  // return the shadow node of head
    	if (!head) 
    	    return NULL;
    	if (hmap.find(head) != hmap.end())
    		return hmap.find(head)->second;
    
    	RandomListNode* node = new RandomListNode(head->label);
    	hmap[head] = node;
    	node->next = copyRandomList(head->next);   
    	node->random = copyRandomList(head->random);
    	return node;
    }
