void deleteNode(ListNode* node) {
	ListNode *p = node;
	for (; node->next; node = node->next)
	{
		node->val = node->next->val;
		p = node;
	}
	p->next = NULL;
}