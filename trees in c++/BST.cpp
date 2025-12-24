#include <iostream>
using namespace std;


class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class NodeS {
    public:
    int data;
    NodeS* next;
    NodeS(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
    public:
    NodeS* head;

    LinkedList() {
        head = nullptr;
    }

    NodeS* addToLast(int d) {
        NodeS* newNode = new NodeS(d);
        if(!head) {
            head = newNode;
            return head;
        }
        NodeS* curr = head;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;

        return curr->next;
    }

    NodeS* deleteFromEnd() {
        if(!head) return nullptr;
        NodeS* curr = head;
        if(!curr->next) {
            head = nullptr;
            delete curr;

            return nullptr;
        }
        while(curr->next->next) {
            curr = curr->next;
        }
        NodeS* temp = curr->next;
        curr->next = nullptr;
        delete temp;
    }

    NodeS* getLast() {
        NodeS* curr = head;
        while(curr->next) {
            curr = curr->next;
        }
        return curr;
    }
};

class Stack {
    public:
    LinkedList list;
    NodeS* top;

    Stack() {
        top = nullptr;
    }
    
    void push(int d) {
        top = list.addToLast(d);
    }

    NodeS* pop() {
        return list.deleteFromEnd();
    }

    NodeS* viewTop() {
        return top;
    }
};


class BST {
    public:
    Node* root;

    
    BST() {
        root = nullptr;
    }
    Node* insertRec(Node* p, int key);
    void insertIte(int key);
    Node* searchIte(int key);
    Node* searchRec(Node* t, int key);
    Node* getRoot() {
        return root;
    }
    void preOrder(Node* r);
    void inOrder(Node* r);

    Node* Delete(Node* p, int key);
    Node* InPre(Node *p);
    Node* InSucc(Node *p);
    int height(Node* p);

    void createFromPreorder(int pre[], int n);

    // void createFromPreorder(int pre[], int n) {
    //     Stack s;

    //     int i = 0;
    //     root = new Node(pre[i++]);
    //     Node* p = root;
         
    // }

};

void BST::createFromPreorder(int pre[], int n) {
    Stack stk;
    Node* t;
    int i = 0;
}

Node* BST::searchRec(Node* t, int key) {
    if(t == nullptr) {
        cout << "Not found!" << endl;
    } else if(key == t->data) {
        cout << "Found " << key << endl;
        return t;
    } else if(key < t->data) {
        return searchRec(t->left, key);
    } else {
        return searchRec(t->right, key);
    }
    return nullptr;
}

Node* BST::searchIte(int key) {
    Node* t = root;
    while(t) {
        if(key == t->data) {
            cout << "Found " << key << endl;
            return t;
        } else if(key < t->data) {
            t = t->left;
        } else {
            t = t->right;
        }
    }
    cout << "Not found!" << endl;
    return nullptr;
}

Node* BST::insertRec(Node* p, int key) {
    Node* t = new Node(key);
    if(!p) {
        return t;
    }
    if(key < p->data) {
        p->left = insertRec(p->left, key);
    } else if(key > p->data) {
        p->right = insertRec(p->right, key);
    }
    return p;
}

void BST::insertIte(int key) {
    Node* p = nullptr;
    Node* t = root; 
    Node* newNode = new Node(key);
    if(!t) {
        root = newNode;
        cout << "The root didn't exist! " << key << " is the root now!" << endl;
        return;
    }
    while(t) {
        p = t;
        if(t->data == key) {
            cout << "Number already here!" << endl;
            return;
        } else if(key < t->data) {
            t = t->left;
        } else {
            t = t->right;
        }
    } 
    if(key > p->data) {
        p->right = newNode;
    } else {
        p->left = newNode;
    }

}

void BST::inOrder(Node* r) {
    if(r) {
        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
    } 
    
}

void BST::preOrder(Node* r) {
    if(r) {
        cout << r->data << " ";
        preOrder(r->left);
        preOrder(r->right);
    } 
    
}

// Node* deleteRec(Node* p, int key) {
//     // Node* dNode = searchRec(p, key);
//     // int countR = 0, countL = 0;
//     // Node* r = dNode->right;
//     // Node* l = dNode->left;

//     // Node* rP = nullptr;
//     // while(r && r->left) {
//     //     rP = r;
//     //     countR++;
//     //     r = r->left;
//     // }
//     // Node* lP = nullptr;
//     // while(l && l->right) {
//     //     lP = l;
//     //     countL++;
//     //     l = l->right;
//     // }
//     // if(countL > countR) {
//     //     dNode = l;
//     //     if(lP) lP->right = nullptr;
//     // } else {
//     //     dNode = r;
//     //     if(rP)rP->left = nullptr;
//     // }

//     if(key > p->data) {
//         p->right = deleteRec(p->right, key);
//     } else if(key < p->data) {
//         p->left = deleteRec(p->left, key);
//     } else {
//         if()
//     }

// }

Node* BST::Delete(Node* p, int key) {
    // Node* foundN = nullptr;
    // while(p) {
    //     if(p->data == key) {
    //         foundN = p;
    //         break;
    //     }
    //     if(key > p->data) {
    //         p = p->right;
    //     } else if(key < p->data) {
    //         p = p->left;
    //     }
    // }

    // int countL = 0, countR = 0;
    // Node* lSucc = foundN->left, *lP= lSucc;
    // Node* rSucc = foundN->right, *rP = rSucc;


    // while(lSucc) {
    //     lP = lSucc;
    //     lSucc = lSucc->right;
    //     countL++;
    // }
    // while(rSucc) {
    //     rP = rSucc;
    //     rSucc = rSucc->left;
    //     countR++;
    // }

    // if(countL > countR) {

    // }


    // while(p) {
    //     Node* t = nullptr;
    //     if(key > p->data) {
    //         t = p;
    //         p = p->left;
    //     } else if(key < p->data) {
    //         t = p;
    //         p = p->right;
    //     } else {

    //         if(height(p->left) > height(p->right)) {
    //             Node* pre = InPre(p->left);
    //             t->left = pre->left;
    //             delete p;
    //         } else {
    //             Node* succ = InSucc(p->right);
    //             t->right = succ->right;
    //             delete p;
    //         }

    //         break;
    //     }

    // }
    if(!p) {
        return nullptr;
    }
    if(p->left == nullptr && p->right == nullptr ) {
        if(p == root) root = nullptr;
        delete p;
        return nullptr;
    }
    if(key < p->data) {
        p->left = Delete(p->left, key);
    } else if(key > p->data) {
        p->right = Delete(p->right, key);
    } else {
        if(height(p->left) > height(p->right)) {
           Node* q = InPre(p->left);
           p->data = q->data;

           p->left = Delete(p->left, q->data);
        } else {
            Node* q = InSucc(p->right);
            p->data = q->data;

            p->right = Delete(p->right, q->data);
        }
    }
    return p;
    
}

int BST::height(Node* p) {
    int x, y;

    if(!p) {
        return 0;
    }
    x = height(p->left);
    y = height(p->right);

    return (x > y) ? x + 1 : y + 1;
}

Node* BST::InPre(Node *p) {
    while (p && p->right != nullptr){
        p = p->right;
    }
    return p;
}
 
Node* BST::InSucc(Node *p) {
    while (p && p->left != nullptr){
        p = p->left;
    }
    return p;
}

int main() {
    int arr[] = {9, 15, 5, 4, 20, 16, 2, 8, 12, 1, 3, 6}; 
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    BST tR, tI;
    // Applying recursive functions
    tR.root = tR.insertRec(tR.getRoot(), arr[0]);
    for(int i = 1; i< size; i++) {
        tR.insertRec(tR.getRoot(), arr[i]);
    }

    tR.inOrder(tR.getRoot());
    tR.Delete(tR.getRoot(), 8);
    tR.inOrder(tR.getRoot());
    tR.searchRec(tR.getRoot(), 15);
    tR.searchIte(15);



    // Applying iterative functions
    for(int i = 0; i <size; i++) {   // Iterative insert
        tI.insertIte(arr[i]);
    }
    // deleteRec(tR.getRoot(), 8);
    tI.inOrder(tR.getRoot());
    tI.searchRec(tI.getRoot(), 15);
    tI.searchIte( 15);
}