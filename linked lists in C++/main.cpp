#include "singly.cpp"
#include "findMax.hpp"
#include "MoveToHead.hpp"
#include "FromArray.hpp"
#include "lengthOfLL.hpp"
#include "sum.hpp"

int main() {
    int array[5] {1, 2, 3, 4, 5};
    // Create a linkedList using an array
    Node* listFromArray = create(array, 5);
    display(listFromArray);

    LinkedList list;
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtHead(-10);
    list.insertAtHead(-20);
    
    list.printTheList();

    list.insertAtPosition(30.5, 4);
    list.printTheList();

    list.deleteAtHead();
    list.deleteAtEnd();

    list.printTheList();



    list.displayRecursively(list.head);
    cout << "Max in the list is: " << list.maxInTheList() << endl;
    
    cout << list.length() << endl;
    cout << list.sum() << endl;

    

    

    return 0;
}