#include <iostream>
using namespace std;

class Stack {
    private:
    int top;
    char* arr = new char[100];
    public:
    Stack() {
        top = -1;
    }
    void push(char data) {
        if(top >= 99) {
            cout << "Stack overflow! " << endl;
            return;
        }
        arr[++top] = data;
        cout << "Pushed " << data << " to stack\n";
    }
    char pop() {
        if(top < 0) {
            cout << "Stack underflow! " << endl;
            return -1;
        }
        return arr[top--];
    }
    bool isEmpty() {
        return (top < 0);
    }
    bool isFull() {
        return (top == 99);
    }
    char atTop() {
        return (!isEmpty()) ? arr[top] : '\0';
    }
    void display() {
        if(isEmpty()) {
            cout << "Stack is empty! ";
            return;
        }
        for(int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
    }
};


bool isOperator(char x) {
    if(x == '+' || x == '*' || x == '-' || x == '/') {
        return true;
    } 
    return false;
}

int preCheck(char x) {
    if(x == '+' || x == '-') {
        return 1;
    } else if(x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

char* infixToPosfix(char infix[], int size) {
    Stack stack;
    char* postfix = new char[size];
    int i = 0, j = 0;
    while(infix[i] != '\0') {
        if(isOperator(infix[i])) {
            if(stack.isEmpty()) {
                stack.push(infix[i]);
                i++;
                continue;
            } else {
                while(preCheck(infix[i]) <= preCheck(stack.atTop())) {                
                    postfix[j] = stack.pop();
                    j++;
                }
                if(preCheck(infix[i]) > preCheck(stack.atTop())) {
                    stack.push(infix[i]);
                    i++;
                    continue;
                }
                continue;
            }
            
        } else {
            
            postfix[j] = infix[i];
            i++;
            j++;
        }
    }
    while(!stack.isEmpty()) {
        postfix[j] = stack.pop();
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}


int main() {
    char* infix = "a+b*c-d/e\0";
    char* postfix = infixToPosfix(infix, 10);
    int i = 0;
    while(postfix[i] != '\0') {
        cout << postfix[i] << endl;
        i++;
    }
}