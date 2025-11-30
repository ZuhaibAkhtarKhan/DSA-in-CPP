#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int v) {
        data = v;
        next = nullptr;
    } 
};

class LinkedList {
    public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void addToEnd(int v) {
        Node* newNode = new Node(v);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while(temp!=nullptr) {
            cout << temp->data;
            (temp->next != nullptr)? (cout << " -> "):(cout << "");
            temp = temp->next;
        }
    }

    void makeCycle(int pos) {
        Node* node = head;
        Node* tail = head;
        for(int i = 1; i < pos && node != nullptr; i++) {
            node = node->next;
        }
        while(tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = node;
    }
    
};

int detectNodeCycle(Node* head) {
    Node* slowPtr = head;
    Node* fastPtr = head;
    while(fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr == fastPtr) {
            break;
        }
    }

    Node* checkNode = head;
    int count = 1;
    int l = 1;
    while(checkNode != slowPtr) {
        bool d = false;
        Node* temp = slowPtr;
        do {
            if(temp == checkNode) {
                cout << "Loop starts at " << count << endl;
                d = true;
                break;
            }
            temp = temp->next;
        } while(temp != slowPtr);
        if(d) break;
        else {
            checkNode = checkNode->next;
            count++;
        }
        
    }
    int data = checkNode->data;
    while(slowPtr->next != checkNode) {
        slowPtr = slowPtr->next;
    }
    slowPtr->next = nullptr;

    Node* temp = head;
    if(temp == checkNode) {
        Node* dNode = head;
        head = dNode->next;
        delete dNode;
    } else {
        while(temp->next != checkNode) {
            temp = temp->next;
        }
        Node* dNode = temp->next;
        temp->next = dNode->next;

        delete dNode;
    }
    
    temp = head;
    while(temp!=nullptr) l++, temp = temp->next;
    cout << "Loop removed from Node # " << l << " > Node # " << count << endl;
    return data;

}

int main() {
    LinkedList list;
    list.addToEnd(11);
    list.addToEnd(3);
    list.addToEnd(8);
    list.addToEnd(2);
    list.addToEnd(1);
    list.makeCycle(5);
    cout << detectNodeCycle(list.head);
}