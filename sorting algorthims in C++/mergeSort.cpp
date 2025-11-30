#include <iostream>
using namespace std;

void mergeSort(int arr[], int size) {
    
}

int main() {
    int size;
    cout << "Size of the array: ";
    cin >> size;
    int* array = new int[size];
    for(int i = 0; i < size; i++) {
        cout << "Enter " << ((i==0) ? "the first " : ((i==size-1)? "the last": "the next")) << " element: ";
        cin >> array[i];
    }
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
    cout << "\nSorted by Merge sort: ";
    mergeSort(array, size);
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}