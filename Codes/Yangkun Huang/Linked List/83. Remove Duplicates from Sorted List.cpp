ListNode* deleteDuplicates(ListNode* head) {
	ListNode headNode(0);
	headNode.next = head;
	ListNode *p = headNode.next;
	if (head == NULL)
		return head;
	for (; p->next != NULL;)
		if (p->val == p->next->val)
			p->next = p->next->next;
		else
			p = p->next;
	return head;
}
