#include <iostream>
#include <string>
using namespace std;

bool isBalanced(const string& parentheses) {
    char stack[1000];
    int top = -1;
    for (int i = 0; i < parentheses.length(); i++) {
        if (parentheses[i] == '(') stack[++top] = '(';
        else if (parentheses[i] == ')') {
            if (top == -1) return false;
            top--;
        }
    }
    return top == -1;
}

int main() {
    string p;
    cout << "Enter parentheses string: ";
    cin >> p;
    cout << (isBalanced(p) ? "Balanced" : "Not Balanced") << endl;
}

