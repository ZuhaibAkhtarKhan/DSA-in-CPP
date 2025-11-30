#include <iostream>
using namespace std;

class Node {
    public: 
    int data; 
    Node* next;
    Node* prev;

    Node(int v) {
        data = v;
        next = nullptr;
        prev = nullptr;
    }
};

Node* head = nullptr;
int n = 0;
void addToEnd(int v) {
    Node* newNode = new Node(v);
    if(head == nullptr) {
        head = newNode;
        n++;
        return;
    }
    Node* temp = head;

    while(temp->next != nullptr) {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    n++;
}

void print() {
    Node* temp = head;
    while(temp!= nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool positionHead(int pos) {
    if(pos > 1 && pos <= n) {
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        Node* prevHead = head;
        temp->next = prevHead;
        prevHead->prev = temp;

        temp = head;
        for(int i = 1; i< pos && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        head = temp->next;
        head->prev = nullptr;
        temp->next = nullptr;
    } else if(pos == 1) {
        return true;
    } else {
        cout << "Invalid position entered!" << endl;
        return false;
    }
    return true;
}

int main() {

    // adding to the list
    addToEnd(11);
    addToEnd(3);
    addToEnd(8);
    addToEnd(2);
    addToEnd(1);
    cout << "Original list: ";
    print();

    cout << "Enter the position you wanna shift head to: ";
    int pos;
    cin >> pos;
    if(positionHead(pos)) {
        cout << "New list: ";
        print();
    }
} 