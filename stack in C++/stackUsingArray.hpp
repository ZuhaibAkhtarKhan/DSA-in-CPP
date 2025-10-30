namespace stackArr {
    class Stack {
        private:
        int top;
        int* arr = new int[100];

        public:
        Stack() {
            top = -1;
        }

        void push(int data) {
            if(top > 99) {
                cout << "Stack overflow! " << endl;
                return;
            }
            arr[++top] = data;
            cout << "Pushed " << data << " to stack\n";
        }

        int pop() {
            if(top < 0) {
                cout << "Stack underflow! " << endl;
                return -1;
            }
            return arr[top--];
        }

        int peek(int i) {
            if(i < 0) {
                cout << "Stack underflow! ";
                return -1;
            } else if(i > top) {
                cout << "Stack overflow" << endl;
                return -1;
            }
            return arr[i];
        }

        int stackTop() {
            if(top < 0) {
                cout << "Stack is empty!";
                return -1;
            }
            return arr[top];
        }

        bool isEmpty() {
            return (top < 0);
        }

        bool isFull() {
            return (top == 99);
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
}
