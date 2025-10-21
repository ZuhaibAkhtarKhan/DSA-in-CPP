// Linked list is a linear data structure that allows the user to store data in non-contaguous memory locations

#include <iostream>
using namespace std;


class Node {
    public:
        float data;
        Node* next;

    Node() {
        data = 0;
        next = NULL;
    }
    Node(float data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    public:
        Node* head;
        LinkedList() {
            head = NULL;
        }

        // Insertion
        void insertAtHead(float data) {
            Node* newNode = new Node(data);

            if(head == NULL) {
                head = newNode;
                return;
            }
            newNode->next = head;
            this->head = newNode;
        }

        void insertAtPosition(float data, int position) {
            if(position < 1) {
                cout << "Insert a valid position!";
                return;
            }
            if(position == 1) {
                insertAtHead(data);
                return;
            } 

            Node* curr = head;
            for(int i = 1; i < position-1 && curr != NULL; i++) {
                curr = curr->next;
            }
            if(curr == NULL) {
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
            curr->next = curr->next->next;
            delete temp;
        }

        // Printing the list
        void printTheList() {
            Node* curr = head;
            while(curr != NULL) {
                cout << curr->data;
                if(curr->next != NULL) {
                    cout << "-> ";
                }
                curr = curr->next;
            }
            cout << endl;
        }

        void displayRecursively(Node* curr) {
            if(curr != nullptr) {
                cout << curr->data << ((curr->next != nullptr) ? "-> ": "");
                displayRecursively(curr->next);
            }
        }
};

int main() {
    LinkedList list;
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    
    list.printTheList();

    list.insertAtPosition(30.5, 4);
    list.printTheList();

    list.deleteAtHead();
    list.deleteAtEnd();

    list.printTheList();

    list.displayRecursively(list.head);

    

    return 0;
}