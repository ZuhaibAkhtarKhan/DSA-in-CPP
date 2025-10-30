#include <iostream>
using namespace std;

#include "stackUsingLinkedList.hpp"

#include "stackUsingArray.hpp"

int main() {

    cout << "Using Array: " << endl;
    stackArr::Stack stackA;

    cout << stackA.isEmpty() << endl;
    cout << stackA.isFull() << endl;

    stackA.push(0);
    stackA.push(10);
    stackA.push(20);
    stackA.push(30);
    stackA.push(40);
    stackA.push(50);
    stackA.push(60);
    cout << stackA.pop() << endl;

    cout << "The last element is: " << stackA.stackTop() << endl;
    cout << "The element at index 3 is: " << stackA.peek(3) << endl;

    stackA.display();


    cout << "\n\nUsing Linked List: " << endl;
    stackLL::Stack stackLL;

    stackLL.push(0);
    stackLL.push(10);
    stackLL.push(20);
    stackLL.push(30);
    stackLL.push(40);
    stackLL.push(50);
    stackLL.push(60);
    stackLL.pop();

    cout << "The last element is: " << stackLL.peek() << endl;

    stackLL.display();
}