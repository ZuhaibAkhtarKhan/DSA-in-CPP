#include <iostream>
using namespace std;

int main() {
    cout << "Dynamicall allocating a 2D Array ..." << endl;
    int rows, cols;
    cout << "Enter rows and then columns: " << endl;
    cin >> rows >> cols;

    int** array = new int*[rows];

    for(int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    int num = 2;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i][j] = num;
            num = num + 2;
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
} 