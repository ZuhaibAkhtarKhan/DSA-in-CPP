#include <iostream>
using namespace std;

void countSort(int arr[], int size, int max) {
    int* count = new int[max+1]();
    for(int i = 0; i< size; i++) {
        count[arr[i]]++;
    }

    int j = 0;
    for(int i = 0; i<= max && j < size; i++) {
        while(count[i]) {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }

    delete[] count;
}

int main() {
    int size;
    cout << "Size of the array: ";
    cin >> size;
    int* array = new int[size];

    int max = 0;
    for(int i = 0; i < size; i++) {
        cout << "Enter " << ((i==0) ? "the first " : "the next") << " element: ";
        cin >> array[i];
        if(max < array[i]) max = array[i];
    }
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
    cout << "\nSorted by Count sort: ";
    countSort(array,size, max);
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}