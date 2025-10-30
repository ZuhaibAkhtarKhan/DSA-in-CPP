namespace stackLL {

    class Node {
        public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = nullptr;
        }
    };

    class Stack {
        private:
        Node* top; // Overflow only occurs when memory is exhausted

        public:
        Stack() {
            top = nullptr;
        }

        void push(int data) {

            Node* newNode = new Node(data);
            if(top == nullptr) {
                top = newNode;
                return;
            }
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if(top == nullptr) {
                cout << "Stack underflow! " << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        int peek() {
            if(top == nullptr) {
                cout << "Stack is empty! " << endl;
                return -1;
            }
            return top->data;
        }

        bool isEmpty() {
            return (top == nullptr);
        }

        void display() {
            if(top == nullptr) {
                cout << "Stack is empty! " << endl;
                return;
            }
            Node* temp = top;
            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    };

}

