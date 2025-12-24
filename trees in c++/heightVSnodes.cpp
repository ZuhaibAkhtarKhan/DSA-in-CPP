#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Choose: \n";
    cout << "1. Height to node\n";
    cout << "2. Nodes to height\n";
    int opt = 0;
    while(opt < 1 || opt > 2) {
        cout << "Input: ";
        cin >> opt;
    }
    switch(opt) {
        case 1: {
            cout << "General binary tree: \n";
            cout << "Enter the height you wanna know max and min nodes for: ";
            int h;
            cin >> h;

            cout << "Min nodes: " << h + 1 << endl;
            // int max = 1;
            // while(h) {
            //     max += pow(2, h);
            //     h--;
            // }

            // OR

            int max = pow(2, h+1) - 1;

            cout << "Max nodes: " << max << endl;

            cout << "\nStrict binary tree: \n";
            cout << "Enter the height you wanna know max and min nodes for: ";
            cin >> h;

            cout << "Min nodes: " << 2*h + 1 << endl;
            // int max = 1;
            // while(h) {
            //     max += pow(2, h);
            //     h--;
            // }

            // OR

            max = pow(2, h+1) - 1;

            cout << "Max nodes: " << max << endl;

            break;
        }
        case 2: {
            cout << "General binary tree: \n";
            cout << "Enter the nodes you wanna know min and max height for: ";
            int n;
            cin >> n;
            cout << "Max height: " << n - 1 << endl;
            cout << "Min height: " << round(log2(n+1) - 1) << endl;

            cout << "Strict binary tree: \n";
            cout << "Enter the nodes you wanna know min and max height for: ";
            cin >> n;
            cout << "Max height: " << (n - 1)/2 << endl;
            cout << "Min height: " << round(log2(n+1) - 1) << endl;
            break;
        }
        default: {
            break;
        }
    }
    

}