#include <iostream>
using namespace std;

class Queue {
    public: 
    int* arr;
    int front, rear;

    Queue(int size) {
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == 100 - 1;
    }

    void enqueue(int data) {
        if(isFull()) {
            cout << "Queue is Full! " << endl;
            return;
        }

        if(isEmpty()) {
            front = 0;
        }

        arr[++rear] = data;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty! ";
            return -1;
        }
        int value = arr[front];
        front++;

        if(isEmpty()) {
            front = rear = -1;
        }

        return value;
    }

    int getFront() {
        if(isEmpty()) {
            cout << "Queue is empty! " << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) {
            cout << "Queue is empty! " << endl;
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is empty! ";
            return;
        }
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Queue() {
        delete arr;
    }
};

int main() {
    Queue queue(100);

    cout << queue.isEmpty() << endl;
    cout << queue.isFull() << endl;

    queue.enqueue(0);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.dequeue();

    queue.display();


}