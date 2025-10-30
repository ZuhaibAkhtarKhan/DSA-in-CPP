#include <iostream>
using namespace std;

#include "singly.hpp"

#include "FromArray.hpp"


#include "doubly.hpp"

#include "circular.hpp"

int main() {

    cout << "Singly: " << endl;
    int array[5] {1, 2, 3, 4, 5};
    // Create a linkedList using an array
    singly::Node* listFromArray = create(array, 5);
    display(listFromArray);

    singly::LinkedList list;
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtHead(-10);
    list.insertAtHead(-20);
    
    list.printTheList();

    list.insertAtPosition(30.5, 7);
    list.printTheList();

    list.deleteAtHead();
    list.deleteAtEnd();

    list.printTheList();



    list.displayRecursively(list.head);
    cout << "Max in the list is: " << list.maxInTheList() << endl;
    
    cout << list.length() << endl;
    cout << list.sum() << endl;


    list.insertAtEnd(40);
    list.printTheList();
    list.deleteDuplicates();
    list.printTheList();
    cout << list.isSorted() << endl;
    list.insertSorted(0);
    list.printTheList();


    cout << "Concatenating: " << endl;
    singly::LinkedList list1;
    singly::LinkedList list2;
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);
    list2.insertAtEnd(40);
    list2.insertAtEnd(50);
    list2.insertAtEnd(60);

    singly::Node* newList = concatenate(list1.head, list2.head);
    singly::Node* temp = newList;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }


    cout << "\nDoubly: " << endl;
    
    doubly::LinkedList doublyList;
    doublyList.forward();
    doublyList.reverse();
    doublyList.insertionAtHead(10);
    doublyList.insertionAtEnd(20);
    // doublyList.insertionAtEnd(30);
    doublyList.insertionAtEnd(40);
    doublyList.insertionAtEnd(50);
    doublyList.insertAtPosition(3, 30);
    doublyList.forward();
    doublyList.reverse();
    
    doublyList.deleteFromHead();
    doublyList.deleteFromTail();
    doublyList.deleteAtPosition(2);
    doublyList.forward();
    doublyList.reverse();


    cout << "Doubly Circular: " << endl;
    circular::LinkedList circularList;
    circularList.insertionAtHead(10);
    circularList.insertionAtTail(20);
    circularList.insertionAtPosition(3, 30);
    circularList.insertionAtTail(40);
    circularList.insertionAtTail(50);
    circularList.insertionAtTail(50);

    circularList.display();

    circularList.deleteFromEnd();
    circularList.deleteFromHead();
    circularList.deleteAtPosition(3);

    circularList.display();

    return 0;
}