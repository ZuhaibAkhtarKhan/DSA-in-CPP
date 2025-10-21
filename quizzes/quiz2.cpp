#include <iostream>
using namespace std;

void moveZeros(int arr[], int size) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] == 0 && arr[j+1] != 0) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            
        }
    }
}

// With one loop
void moveZerosOn(int arr[], int size) {
    int nonZeroIndex = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonZeroIndex]);
            nonZeroIndex++;
        }
    }
}

int main() {
    int arr[5] = {0, 1, 0, 2, 3};
    moveZeros(arr, 5);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}