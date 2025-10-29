// Find Max in the list

float singly::LinkedList::maxInTheList() {
    if(head == nullptr) {
        cout << "List is empty! " << endl;
        return 0;
    }
    float max = head->data;
    Node* curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
        if(max < curr->data) {
            max = curr->data;
        }
    }
    return max;
}