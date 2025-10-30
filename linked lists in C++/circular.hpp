// Lets apply with doubly linked list
namespace circular {
    class Node {
        public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) {
            this->data = data;
            next = nullptr;
            prev = nullptr;
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
                head->next = head;
                head->prev = head;
                return;
            }
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev = newNode;
            head->prev->next = newNode;
            head = newNode;
        }

        void insertionAtTail(int data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                head->next = head;
                head->prev = head;
                return;
            }
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
        }

        void insertionAtPosition(int pos, int data) {
            
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                head->next = head;
                head->prev = head;
                return;
            }
            if(pos == 1) {
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev = newNode;
                head->prev->next = newNode;
                head = newNode;
                return;
            }
            Node* curr = head;
            for(int i = 1; i < pos - 1; i++) {
                curr = curr->next;
                if(curr->next == head) {
                    cout << "Position out of range!" << endl;
                    break;
                }
            }
            if(curr->next == head) {
                cout << "Adding to tail: " << endl;
                insertionAtTail(data);
                return;
            }

            newNode->next = curr->next;
            newNode->prev = curr;
            if(curr->next != head) {
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
            if(head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* tail = head->prev;
            head->next->prev = tail;
            tail->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void deleteFromEnd() {
            if(head == nullptr) {
                cout << "Nothing to delete!" << endl;
                return;
            }
            if(head->next == head) {
                cout << "There is just one node; Deleted!" << endl;
                delete head;
                head = nullptr;
                return;
            }
            Node* tail = head->prev;
            tail->prev->next = head;
            head->prev = tail->prev;
            delete tail;
        }

        void deleteAtPosition(int pos) {
            if(head == nullptr) {
                cout << "Nothing to delete!" << endl;
                return;
            }
            if(head->next == head || pos <= 0) {
                if(pos == 1) {
                    delete head;
                    head = nullptr;
                } else {
                    cout << "Invalid Position!" << endl;
                }
                return;
            }
            if(pos == 1) {
                deleteFromHead();
                return;
            }
            Node* temp = head;
            for(int i = 1; i < pos - 1; i++) {
                temp = temp->next;
                if(temp->next == head) {
                    cout << "Invalid position!" << endl;
                    return;
                }                

            }
            Node* node = temp->next;
            temp->next = node->next;
            node->next->prev = temp;

            delete node;


        }

        // display
        void display() {
            if(head == nullptr) {
                cout << "List is empty!" << endl;
                return;
            }
            Node* curr = head;
            do {
                cout << curr->data << ((curr->next != head) ? " <-> ": "\n");
                curr = curr->next;
            } while (curr != head);
        }

    };
}