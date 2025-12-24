#include <iostream>
using namespace std;

class Node {
    public:
    Node* left;
    int data;
    Node* right;

    int height;

    Node (int d) {
        data = d;
        left = right = nullptr;
        height = -1;
    }
};

Node* root = nullptr;

 

int main() {

}