#include <iostream>
#include <string>
using namespace std;

string reverseString(const string& input) {
    char stack[1000];
    int top = -1;
    for (int i = 0; i < input.length(); i++) stack[++top] = input[i];
    string reversed = "";
    while (top != -1) reversed += stack[top--];
    return reversed;
}

int main() {
    string str;
    cout << "Enter string to reverse: ";
    cin >> str;
    cout << reverseString(str) << endl;
}
