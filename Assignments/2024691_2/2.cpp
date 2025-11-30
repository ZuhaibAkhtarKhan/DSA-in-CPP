#include <iostream>
using namespace std;

class Person {
    public:

    string name;
    string address;
    string number;

    Person(string n="", string add="", string num="") {
        name = n;
        address = add;
        number = num;
    }  
};

class Node {
    public:
    Person p;
    Node* next;

    Node(Person p) {
        this->p = p;
        next = nullptr;
    }
};

class LinkedList {
    public:
    Node* head;
     
    LinkedList() {
        head = nullptr;
    }

    void add(Person p) {
        Node* newNode = new Node(p);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        if(newNode->p.name < head->p.name) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp != nullptr) {
            
            if(temp->next && newNode->p.name < temp->next->p.name) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            } else if(!temp->next) {
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    void display() {
        if(head) cout << "Contacts list: \n";
        else  {
            cout << "No contacts saved!";
            return;
        }
        Node* temp = head;
        while(temp!=nullptr) {
            cout << temp->p.name << "\n";
            temp = temp->next;
        }
    }

    void find(string n) {
        if(head == nullptr) {
            cout << "No contacts saved!";
            return;
        }
        Node* temp = head;
        while(temp != nullptr) {
            if(temp->p.name == n) {
                cout << "Name: " << temp->p.name;
                cout << "\nAddress: " << temp->p.address;
                cout << "\nNumber: " << temp->p.number;
                cout << "\n";
                return;
            }
            temp = temp->next;
        }
    }
};

int menu() {
    int opt;
    cout << "---Address Book---";
    cout << "\nChoose an option: ";
    cout << "\n1. Add a person";
    cout << "\n2. Find a person";
    cout << "\n3. Show all";
    cout << "\n4. Exit\n";
    cout << "Enter a valid number: ";
    cin >> opt;
    return opt;
}

int main() {
    
    

    LinkedList list;
    int opt;
    do {
        opt = menu();
    } while(opt < 1 || opt  > 4);

    while(true) {
    switch (opt)
    {
    case 1: {
        string n, add, num;
        
        cout << "Name: ";
        cin >> n;
        cout << "Address: ";
        cin >> add;
        cout << "Number: ";
        cin >> num;
        Person p(n, add, num);
        list.add(p);

        break;
    }
    case 2: {
        cout << "Enter the name you want to find: ";
        string name;
        cin >> name;
        list.find(name);
        break;
    }
    case 3: {
        list.display();
        break;
    }
    default: {
        cout << "Thanks. Exiting..." << endl;
        return 0;
    }
    }
    do {
        opt = menu();
    } while(opt < 1 || opt  > 4);
    }
    
}