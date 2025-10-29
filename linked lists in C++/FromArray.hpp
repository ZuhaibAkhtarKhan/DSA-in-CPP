singly::Node* create(int array[], int size) {
    singly::Node *head = new singly::Node(array[0]);
    singly::Node *temp = head;

    for(int i = 1; i < size; i++) {
        singly::Node* newNode = new singly::Node(array[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    return head;
}

void display(singly::Node* head) {
    singly::Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << ((temp->next != nullptr) ? " -> ": "\n");
        temp = temp->next;
    }
}