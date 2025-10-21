#include <iostream>
using namespace std;

int** multiplyMatrices(int A[3][4], int B[4][3]) {
    int** C = new int*[3];
    for(int i = 0; i < 3; i++) {
        C[i] = new int[3];
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = 0;
        }
    }

    for(int k = 0; k < 3; k++) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 4; j++) {
                C[i][k] += A[i][j]*B[j][k];
            }
        }
    }

    return C;
}

int main() {
    int A[3][4] = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};
    int B[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    int** C = multiplyMatrices(A, B);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    
    for(int i = 0; i < 3; i++) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}