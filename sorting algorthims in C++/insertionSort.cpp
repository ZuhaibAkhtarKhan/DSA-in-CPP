#include <iostream>
using namespace std;

void insertionSort(int array[], int size) {
    int key, j;
    for(int i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j= j -1;
        }
        array[j+1] = key;
    }
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
    
    cout << "\nSorted by Insertion sort: ";
    insertionSort(array, size);
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}