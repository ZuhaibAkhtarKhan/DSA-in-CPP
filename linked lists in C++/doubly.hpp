namespace doubly {
    class Node {
        public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;
            prev = nullptr;
            next = nullptr;
        }
    };

    class LinkedList {
        public:
        Node* head;

        LinkedList() {
            head = nullptr;
        }

        // Insertion
        void insertionAtHead(int data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                return;
            }

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        void insertionAtEnd(int data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                return;
            }

            Node* curr = head;
            while(curr->next != nullptr) {
                curr = curr->next;
            }

            newNode->prev = curr;
            curr->next = newNode;

        }

        void insertAtPosition(int pos, int data) {
            
            if(pos == 1) {
                insertionAtHead(data);
                return;
            }
            Node* newNode = new Node(data);
            Node* curr = head;
            for(int i = 1; i < pos - 1 && curr != nullptr; i++) {
                curr = curr->next;
            }
            if(curr == nullptr) {
                cout << "Position invalid!" << endl;
                return;
            }
            newNode->next = curr->next;
            newNode->prev = curr;
            if(newNode->next != nullptr) {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
            
        }

        // Deletion
        void deleteFromHead() {
            if(head == nullptr) {
                cout << "Nothing to delete!" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;

            delete temp;
        }

        void deleteFromTail() {
            if(head == nullptr) {
                cout << "Nothing to delete!" << endl;
                return;
            }
            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            Node* curr = head;
            while(curr->next->next!=nullptr) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }

        void deleteAtPosition(int pos) {
            if(head == nullptr) {
                cout << "Nothing to delete!" << endl;
                return;
            }
            if(pos == 1) {
                deleteFromHead();
                return;
            }
            Node* curr = head;
            for(int i = 1; i < pos - 1 && curr->next != nullptr; i++) {
                curr = curr->next;
            }
            if(curr->next == nullptr) {
                cout << "Invalid position!" << endl;
                return;
            }
            Node* temp = curr->next;
            curr->next = curr->next->next;
            if(curr->next != nullptr) {
                curr->next->prev = curr;
            }
            
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }

        // Display
        void forward() {
            if(head == nullptr) {
                cout << "List is Empty! " << endl; 
                return;
            }

            Node* curr = head;
            while(curr != nullptr) {
                cout << curr->data << ((curr->next != nullptr)?" <-> ": "\n");
                curr = curr->next;
            }
        }

        void reverse() {
            if(head == nullptr ) {
                cout << "List is Empty! " << endl; 
                return;
            }

            Node* curr = head;
            while(curr->next != nullptr) {
                curr = curr->next;
            }
            while(curr != nullptr) {
                cout << curr->data << ((curr->prev != nullptr)?" <-> ": "\n");
                curr = curr->prev;
            }
        }
    };
}
