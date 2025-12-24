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

int nodeHeight(Node* p) {
    int x, y;
    if(!p) {
        return 0;
    }
    x = nodeHeight(p->left);
    y = nodeHeight(p->right);
    return (x>y)?x+1:y+1;
}

int balanceFactor(Node* p) {
    return nodeHeight(p->left) - nodeHeight(p->right);
}

Node* LLRotation(Node* p) {
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);

    if(root == p) {
        root = pl;
    }

    return pl;
}

Node* LRRotation(Node* p) {
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = plr->left;
    p->right = plr->left;

    plr->left = pl;
    plr->right = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if(root == p) {
        root = plr;
    }

    return plr;
}

Node* insertRec(Node* p, int d) {
        
        if(p == nullptr) {
            Node* newNode = new Node(d);
            return newNode;
        }
        if(d < p->data) {
            p->left = insertRec(p->left, d);
        } else {
            p->right = insertRec(p->right, d);
        }

        p->height = nodeHeight(p);

        

        // Rotation (AVL)
        if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {
            return LLRotation(p);
        }  else if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
             return LRRotation(p);
        } //else if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1) {
        //     return RRRotation(p);
        // } else if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1) {
        //     return RLRotation(p);
        // }


        return p;
}

int main() {
    root = insertRec(root, 10);
    insertRec(root, 5);
    insertRec(root, 2);

    cout << root->data << endl;
    return 0;
}