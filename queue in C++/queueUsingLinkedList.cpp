#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Queue {
    public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if(isEmpty()) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty!";
            return -1;
        }

        
        Node* temp = front;
        Node* ret = temp;

        if(front == rear) {
            front = nullptr;
            rear = nullptr;
            return -1;
        }

        front = front->next;
        delete temp;



        return ret->data;        
    }

    int getFront() {
        if(isEmpty()) {
            cout << "Queue is empty!";
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if(isEmpty()) {
            cout << "Queue is empty!";
            return -1;
        }
        return rear->data;
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is empty!";
            return;
        }
        Node* temp = front;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    Queue queue;

    cout << queue.isEmpty() << endl;

    queue.enqueue(0);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    cout << "Rear: " << queue.getRear() << endl;
    cout << "Front: " << queue.getFront() << endl;
    

    queue.dequeue();

    queue.display();


}