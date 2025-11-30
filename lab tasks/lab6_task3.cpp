#include <iostream>
using namespace std;

void selectionSort(int array[], int size) {
    int count = 0;
    for(int i = 0; i< size-1; i++) {
        int minInd = i;
        for(int j = i+1; j < size; j++) {
            if(array[minInd] > array[j]) {
                minInd = j;
            }
        }
        swap(array[i], array[minInd]);
        count++;
        cout << "After pass " << i+1 << ": ";
        for(int k = 0; k < size; k++) cout << array[k] << " ";
        cout << "\n";
    }
    cout << "Swaps performed: " << count << "\n";
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
    
    cout << "\nSorted by Selection sort: \n";
    selectionSort(array, size);
    cout << "Sorted Array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}