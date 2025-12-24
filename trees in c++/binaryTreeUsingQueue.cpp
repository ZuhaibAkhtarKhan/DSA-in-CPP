#include <iostream>
using namespace std;



class Node {
    public: 

    int data;
    Node* left;
    Node* right;

    Node(int v= -1) {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

class Queue {
    private:
    Node** arr;
    int front, rear;
    int size;

    public: 
    Queue(int size) {
        front = -1;
        rear = -1;
        arr = new Node*[size];
        this->size = size;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == 100 - 1;
    }

    void enqueue(Node * n) {
        if(isFull()) {
            cout << "Queue is Full! " << endl;
            return;
        }

        if(isEmpty()) {
            front = 0;
        }

        arr[++rear] = n;
    }

    Node* dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty! ";
            return nullptr;
        }
        Node* value = arr[front];
        front++;

        if(isEmpty()) {
            front = rear = -1;
        }

        return value;
    }

    Node* getFront() {
        if(isEmpty()) {
            cout << "Queue is empty! " << endl;
            return nullptr;
        }
        return arr[front];
    }

    Node* getRear() {
        if(isEmpty()) {
            cout << "Queue is empty! " << endl;
            return nullptr;
        }
        return arr[rear];
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is empty! ";
            return;
        }
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Queue() {
        delete arr;
    }
};

Node* root;

class Tree {
    public:

    Tree() {
        root = nullptr;
    }

    void createTree();
    void preOrder(Node* p);
    void postOrder(Node* p);
    void inOrder(Node* p);
    void levelOrder(Node* p);

    int height(Node* root);
    int count(Node* p);
    int countLeaf(Node* p);
    int countInternal(Node* p);

};



void Tree::createTree() {
    root = new Node;
    Node *p, *t;
    int x;
    Queue q(10);

    cout << "Enter the root value: ";
    cin >> x;
    root->data = x;
    
    q.enqueue(root);

    while(!q.isEmpty()) {
        p = q.dequeue();

        cout << "Enter the left child value of " << p->data << ": ";
        cin >> x;
        if(x != -1) {
            t = new Node;
            t->data = x;

            p->left = t;
            q.enqueue(t);
        }

        cout << "Enter the right child value of " << p->data << ": ";
        cin >> x;
        if(x != -1) {
            t = new Node;
            t->data = x;

            p->right = t;
            q.enqueue(t);
        }
    }

}

void Tree::preOrder(Node* p) {
    if(p) {
        cout << p->data << ", ";
        preOrder(p->left);
        preOrder(p->right);
    }
}

void Tree::postOrder(Node* p) {
    if(p) {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << ", ";
        
    }
}

void Tree::inOrder(Node* p) {
    if(p) {
        inOrder(p->left);
        cout << p->data << ", ";
        inOrder(p->right);
    }
    // Iterative
    
}

void Tree::levelOrder(Node *root) {
    Node* p = new Node;
    Queue q(100);
    q.enqueue(root); 
    cout << root->data << ", ";
    while(!q.isEmpty()) {
        p = q.dequeue();
        if(p->left) q.enqueue(p->left), cout << p->left->data << ", ";
        if(p->right) q.enqueue(p->right), cout << p->right->data << ", ";
    }

}

int Tree::count(Node* p) {
    if(p) {
        return count(p->left) + count(p->right) + 1;
    } 
    return 0;
}

int Tree::height(Node* root) {
    int x = 0, y = 0;
    if(!root) {
        return 0;
    }

    x = height(root->left);
    y = height(root->right);
    if(x > y) return x+1;
    else return y+1; 

}

int Tree::countLeaf(Node* p) {
    int x = 0, y = 0;
    if(p) {
        x = countLeaf(p->left);
        y = countLeaf(p->right);

        if(p->left == nullptr && p->right == nullptr) {
            return x + y + 1;
        } else return x + y;
    }
    return 0;
}

int Tree::countInternal(Node* p) {
    int x = 0, y = 0;
    if(p) {
        x = countInternal(p->left);
        y = countInternal(p->right);

        if(p->left != nullptr || p->right != nullptr) {
            return x + y + 1;
        } else return x + y;
    }
    return 0;
}

int main() {
    Tree t;
    t.createTree();

    t.preOrder(root);
    cout << "\n";
    t.inOrder(root);
    cout << "\n";
    t.postOrder(root);

    cout << "\n";
    t.levelOrder(root);

    cout << "\n" << t.count(root);
    cout << "\n" << t.countLeaf(root);
    cout << "\n" << t.countInternal(root);
    cout << "\n" << t.height(root);
}