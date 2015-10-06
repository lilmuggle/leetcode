void deleteNode(struct ListNode* node) {
    if(node->next != NULL)
    {
        *node = *node->next;
    }
}
