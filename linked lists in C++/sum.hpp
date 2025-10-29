float LinkedList::sum() {
    float sum = 0;
    Node* temp = head;
    while(temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}