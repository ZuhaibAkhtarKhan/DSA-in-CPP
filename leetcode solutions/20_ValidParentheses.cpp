class Solution {
public:
    bool isValid(std::string s) {
        class Stack {
            public:
            char arr[10000];
            int top;

            Stack() {
                top = -1;
            }

            bool isEmpty() {
                return top == -1;
            }

            void push(char val) {
                if(top < 10000) {arr[++top] = val;};
            }

            char pop() {
                return top >= 0 ? arr[top--]: '\0';
            }

            char onTop() {
                return arr[top];
            }
        };

        Stack stack;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] =='(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            }
            if(s[i] == ')') {
                if(stack.onTop() == '(') {
                    stack.pop();
                } else {
                    return 0;
                }
            } else if(s[i] == ']') {
                if(stack.onTop() == '[') {
                    stack.pop();
                } else {
                    return 0;
                }
            } else if(s[i] == '}') {
                if(stack.onTop() == '{') {
                    stack.pop();
                } else {
                    return 0;
                }
            }
                        
        }
        return stack.isEmpty();
    }
};