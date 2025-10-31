class Solution {
public:
    bool isValid(std::string s) {
        class Stack {
        public:
            char arr[10000];
            int top;

            Stack() { top = -1; }

            bool isEmpty() { return top == -1; }

            void push(char val) {
                if (top < 10000) {
                    arr[++top] = val;
                }
            }

            char pop() { return top >= 0 ? arr[top--] : '\0'; }

            char onTop() {
                if (top >= 0) {
                    return arr[top];
                }
                return '\0';
            }
        };

        Stack stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else if ((s[i] == ')' && stack.onTop() == '(') ||
                       (s[i] == ']' && stack.onTop() == '[') ||
                       (s[i] == '}' && stack.onTop() == '{')) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.isEmpty();
    }
};