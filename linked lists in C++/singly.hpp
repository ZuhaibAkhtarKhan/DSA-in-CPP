// Linked list is a linear data structure that allows the user to store data in non-contaguous memory locations

namespace singly {

    class Node {
        public:
            float data;
            Node* next;

        Node() {
            data = 0;
            next = nullptr;
        }
        Node(float data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    class LinkedList {
        public:
            Node* head;
            LinkedList() {
                head = nullptr;
            }

            // Insertion
            void insertAtHead(float data) {
                Node* newNode = new Node(data);

                if(head == nullptr) {
                    head = newNode;
                    return;
                }
                newNode->next = head;
                this->head = newNode;
            }

            void insertAtPosition(float data, int position) {
                if(position < 0) {
                    cout << "Enter a valid position!" << endl;
                    return;
                }
                if(position == 1) {
                    insertAtHead(data);
                    return;
                } 

                Node* curr = head;
                for(int i = 1; i < position-1 && curr != nullptr; i++) {
                    curr = curr->next;
                }
                if(curr == nullptr) {
                    return;
                }
                Node* newNode = new Node(data);

                newNode->next = curr->next;
                curr->next = newNode;
            }

            void insertAtEnd(float data) {
                if(head == nullptr) {
                    insertAtHead(data);
                    return;
                }
                Node* newNode = new Node(data);
                Node* curr = head;
                while(curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = newNode;
                newNode->next = nullptr;
            }

            // Deletion
            void deleteAtHead() {
                if(head == nullptr) {
                    cout << "Nothing to delete!" << endl;
                    return;
                }

                Node* temp = head;
                head = head->next;
                delete temp;
            }

            void deleteAtEnd() {
                if(head == nullptr) {
                    cout << "Nothing to delete!" << endl;
                    return;
                }
                if(head->next == nullptr) {
                    deleteAtHead();
                    return;
                }
                Node* curr = head;
                while(curr->next->next != nullptr) {
                    curr = curr->next;
                }
                Node* temp = curr->next;
                delete temp;
                curr->next = nullptr;
            }

            void deleteAtPosition(int pos) {
                if(head == nullptr) {
                    cout <<"Nothing to delete!" << endl;
                    return;
                }
                if(pos == 1) {
                    deleteAtHead();
                    return;
                }
                Node* curr = head;
                for(int i = 1; i < pos - 1 && curr != nullptr; i++) {
                    curr = curr->next;
                }
                Node* temp = curr->next;
                if(curr->next) {
                    
                    curr->next = temp->next;
                }
                    
                
                delete temp;
            }

            // Printing the list
            void printTheList() {
                Node* curr = head;
                while(curr != nullptr) {
                    cout << curr->data;
                    if(curr->next != nullptr) {
                        cout << "-> ";
                    }
                    curr = curr->next;
                }
                cout << endl;
            }

            void displayRecursively(Node* curr) {
                if(curr != nullptr) {
                    cout << curr->data << ((curr->next != nullptr) ? "-> ": "\n");
                    displayRecursively(curr->next);
                }

            }

            // Find Max in the list
            float maxInTheList() {
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

            // Length of LL
            int length() {
                Node* temp = head;
                int i = 0;
                while(temp!= nullptr) {
                    i++;
                    temp = temp->next;
                }
                return i;
            }

            // sum
            float sum() {
                float sum = 0;
                Node* temp = head;
                while(temp != nullptr) {
                    sum += temp->data;
                    temp = temp->next;
                }
                return sum;
            }

            // Binary search wouldn't work with LinkedLists.

            // Move node to head
            void moveToHead(int pos) {
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

            // is the list sorted
            bool isSorted() {
                Node* curr = head;
                while(curr->next!= nullptr) {
                    if(!(curr->data <= curr->next->data)) {
                        return false;
                    }
                    curr = curr->next;
                }
                return true;
            }

            // insert in a sorted list
            void insertSorted(int data) {
                if(head == nullptr) {
                    cout << "List is empty!" << endl;
                    return;
                }
                if(!isSorted()) {
                    cout << "List is not sorted!";
                    return;
                }
                Node* curr = head;
                int i = 1;
                while(curr->next != nullptr) {
                    if(data < curr->data) {
                        insertAtPosition(data, i);
                        return;
                    }
                    curr = curr->next;
                    i++;
                }
                
            }

            // Delete duplicates
            void deleteDuplicates() {
                if(head == nullptr) {
                    cout << "List is empty! " << endl;
                    return;
                }
                Node* curr, *key = head;
                while(key!= nullptr) {
                    curr = key;
                    while(curr->next != nullptr) {
                        if(key->data == curr->next->data) {
                            Node* temp = curr->next;
                            curr->next = temp->next;
                            delete temp;

                        } else {
                            curr = curr->next;
                        }
                        
                    }
                    key = key->next;
                }
            }

            // Swap nodes 
            void swapNodes(int pos1, int pos2);   // We can just swap the data which is easy but lets actually swap the nodes    

    };
}

singly::Node* concatenate(singly::Node* list1, singly::Node* list2) {
    singly::Node* temp = list1;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = list2;

    return list1;
}