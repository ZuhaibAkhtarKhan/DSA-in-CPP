#include <iostream>
using namespace std;

class Stack {
    private:
    int top;
    int arr[100];

    public:
    Stack() {
        top = -1;
    }

    void push(int data) {
        if(top > 99) {
            cout << "Stack overflow! " << endl;
            return;
        }
        arr[++top] = data;
        cout << "Pushed " << data << " to stack\n";
    }

    int pop() {
        if(top < 0) {
            cout << "Stack underflow! " << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if(top < 0) {
            cout << "Stack is empty! ";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }

    bool isFull() {
        return (top == 99);
    }

    void display() {
        if(top < 0) {
            cout << "Stack is empty! ";
            return;
        }
        for(int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    Stack stack;

    cout << stack.isEmpty() << endl;
    cout << stack.isFull() << endl;

    stack.push(0);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    cout << stack.pop() << endl;

    cout << "The last element is: " << stack.peek() << endl;

    stack.display();

}