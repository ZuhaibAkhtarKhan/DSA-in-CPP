 // Move node to head

void singly::LinkedList::moveToHead(int pos) {
    Node* curr = head;
    for(int i = 1; i < pos - 1 && curr->next != nullptr; i++) {
        curr = curr->next;
    }
    if(curr->next == nullptr) {
        return;
    }
    Node* node = curr->next;
    curr->next = node->next;
    node->next = head;
    head = node;  
}