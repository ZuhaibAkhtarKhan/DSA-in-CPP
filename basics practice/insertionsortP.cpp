#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    int key, j;
    for(int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            if(key < arr[j]) {
                arr[j+1] = arr[j];
                j = j - 1;
            }
            arr[j+1] = key;
        }
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