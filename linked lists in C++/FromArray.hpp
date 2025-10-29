Node* create(int array[], int size) {
    Node* head = new Node(array[0]);
    Node* temp = head;

    for(int i = 1; i < size; i++) {
        Node* newNode = new Node(array[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    return head;
}

void display(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << ((temp->next != nullptr) ? " -> ": "\n");
        temp = temp->next;
    }
}