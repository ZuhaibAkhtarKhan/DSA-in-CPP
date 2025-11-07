#include <iostream>
using namespace std;

class Parent {
    public:
    void getinfo() {
        cout << "Parent class" << endl;
    }


    virtual void hello() {
        cout << "HEllo from parent" << endl;
    }
};

class Child : public Parent {
    public:
    void getinfo() {
        cout << "Child class" << endl;
    }
    void hello() {
        cout << "HEllo from child" << endl;
    }
    
};

int main() {
      Child c1;
      c1.getinfo();
      c1.hello();
}