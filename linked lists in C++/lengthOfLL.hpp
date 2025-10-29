int singly::LinkedList::length() {
    Node* temp = head;
    int i = 0;
    while(temp!= nullptr) {
        i++;
        temp = temp->next;
    }
    return i;
}