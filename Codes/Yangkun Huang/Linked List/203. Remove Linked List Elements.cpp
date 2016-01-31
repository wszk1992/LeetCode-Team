ListNode* removeElements(ListNode* head, int val) {
	ListNode headNode(0);
	headNode.next = head;
	ListNode *p = head, *q = &headNode;
	if (head == NULL)
		return head;
	for (; p->next != NULL; p = p->next)
		if (q->next->val == val)
			q->next = q->next->next;
		else
			q = p;
	if (p->val == val)
		q->next = NULL;
	return headNode.next;
}