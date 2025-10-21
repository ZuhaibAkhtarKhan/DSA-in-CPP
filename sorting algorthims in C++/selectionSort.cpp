#include <iostream>
using namespace std;

void selectionSort(int array[], int size) {
    int temp;
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            if(array[j] < array[i]) {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
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
    
    cout << "\nSorted by Selection sort: ";
    selectionSort(array, size);
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}