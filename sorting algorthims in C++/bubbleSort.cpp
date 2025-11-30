#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {    
    int temp;
    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for(int j = 0; j < size-1-i; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
            
        }
        if(!swapped) {
            return;
        }
    }

    
}

int main() {
    int size;
    cout << "Size of the array: ";
    cin >> size;
    int* array = new int[size];
    for(int i = 0; i < size; i++) {
        cout << "Enter " << ((i==0) ? "the first " : "the next") << " element: ";
        cin >> array[i];
    }
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\nSorted by Bubble sort: ";
    bubbleSort(array, size);
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}