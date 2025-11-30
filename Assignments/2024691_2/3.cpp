#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int v) {
        data = v;
        next = prev = nullptr;
    }
};

class LinkedList {
    Node* head;

    public:
    LinkedList() {
        head = nullptr;
    }

    void add(int v) {
        Node* newNode = new Node(v);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node* tail = head;
        while(tail->next != nullptr) {
            tail = tail->next;
        }
        newNode->prev = tail;
        tail->next = newNode;

    }
    void display() {
        if(head == nullptr) {
            cout << "List is empty!";
            return;
        }
        Node* temp = head;
        while(temp!=nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void swap(int a, int b) {
        if(a == b) {
            cout << "No need to swap!" << endl;
            return;
        } else if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        if(b - a >= 2) {
            Node* nodeA = head;
            Node* nodeB = head;
            for(int i = 1; i<a && nodeA != nullptr; i++) {
                nodeA = nodeA->next;
            }
            for(int i = 1; i<b && nodeB != nullptr; i++) {
                nodeB = nodeB->next;
            }

            Node* nodeAp = nodeA->prev;
            Node* nodeAn = nodeA->next;


            nodeA->next = nodeB->next;
            nodeA->prev = nodeB->prev;

            Node* nodeBp = nodeB->prev;
            Node* nodeBn = nodeB->next;

            nodeB->next = nodeAn;
            nodeAn->prev = nodeB;

            nodeB->prev = nodeAp;
            if(nodeAp) {
                nodeAp->next = nodeB;
            } else {
                head = nodeB;
            }
            
            if(nodeBn) {
                
                nodeBn->prev = nodeA;
            } else {
                nodeBn = nodeA;
            }
            nodeBp->next = nodeA;
            
            
        } else if(b - a == 1) {
            Node* nodeA = head;
            for(int i = 1; i < a && nodeA != nullptr; i++) {
                nodeA = nodeA->next;
            }
            if(!nodeA || !nodeA->next) {
                cout << "Invalid nodes!";
                return;
            }
            Node* nodeB = nodeA->next;

            if(nodeA->prev) {
                Node* nodeAp = nodeA->prev;
                nodeAp->next = nodeB;
                nodeB->prev = nodeAp;
            } else {
                nodeB->prev = nullptr;
                head = nodeB;
            }
            
            Node* nodeBn = nodeB->next;
            if(nodeB->next) {
                nodeB->next->prev = nodeA;

                
            } 
            nodeB->next = nodeA;
            
            nodeA->next = nodeBn;
            nodeA->prev = nodeB;

            return;

        }
    }
};

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.display();

    list.swap(6, 1);
    list.display();
}