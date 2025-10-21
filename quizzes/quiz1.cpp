#include <iostream>
using namespace std;

void function(int array[], int size) {
    int temp, n = size - 1;
    for(int i = 0; i < size/2; i++) {
        temp = array[n];
        array[n] = array[i];
        array[i] = temp;
        n--;
    }
}

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    function(arr, 5);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}