#include <iostream>
#include <string>
using namespace std;


class Student {
    public:
    string name;
    float* cgpaPtr;

    Student(string name, float cgpa) {
        this->name = name;
        cgpaPtr = new float;
        *cgpaPtr = cgpa;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }

    Student(Student &obj) {
        this->name = obj.name;
        cgpaPtr = new float(*(obj.cgpaPtr)); // deep copy
    } 

    ~Student() {
        delete cgpaPtr;
    }

};

int main() {
    
    Student s1("Zuhaib AKhtar", 3.41);
    Student s2(s1);
    s1.getInfo();
    s2.getInfo();
    *(s2.cgpaPtr) = 50;
    s1.getInfo();
    s2.getInfo();
    
    return 0;
}