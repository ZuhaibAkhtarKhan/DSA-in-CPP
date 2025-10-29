#include <iostream>
using namespace std;

#include "singly.hpp"

#include "FromArray.hpp"


#include "doubly.hpp"

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


    

    return 0;
}