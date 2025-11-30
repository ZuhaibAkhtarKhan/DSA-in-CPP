#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Enter the height you wanna know max and min nodes for: ";
    int h;
    cin >> h;

    cout << "Min nodes: " << h + 1 << endl;
    int max = 1;
    while(h) {
        max += pow(2, h);
        h--;
    }

    cout << "Max nodes: " << max << endl;

}