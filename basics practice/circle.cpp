#include <iostream>
#include <cmath>
using namespace std;

void drawCircle(int r) {
    for (int y = r; y >= -r; y--) {
        for (int x = -r; x <= r; x++) {
            if (abs(x * x + y * y - r * r) < r) // Rough threshold
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    drawCircle(20);
}