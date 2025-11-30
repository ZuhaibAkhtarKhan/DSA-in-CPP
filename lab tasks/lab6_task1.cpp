#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    int count = 0;
    for(int i = 0; i< size-1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                count++;
            }
        }
        
        cout << "After pass " << i+1 << ": ";
        for(int k = 0; k < size; k++) cout << arr[k] << " ";
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
        cout << "Enter " << ((i==0) ? "the first " : "the next") << " student's marks: ";
        cin >> array[i];
    }
    cout << "Original Marks: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\nSorted by Bubble sort: \n";
    bubbleSort(array, size);
    cout << "Sorted marks: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}