#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        cout << "Parent"  << endl;
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
    // name, age, roll no
    public:
    int rollno;

    void getInfo() {
        cout << name << endl;
        cout << age << endl;
        cout << rollno << endl;
    }

    Student(string name, int age, int rollno): Person(name, age) {
        cout << "Derived" << endl;
        this->rollno = rollno;
    }
};

int main() {
    Student s("Zuhaib", 21, 2024691);
}