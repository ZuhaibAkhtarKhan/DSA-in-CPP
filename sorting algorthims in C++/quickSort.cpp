#include <iostream>
using namespace std;

int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l, j = h;

    do {
        do{i++;} while(i <= h && arr[i] <= pivot);
        do{j--;} while(j >= l && arr[j] > pivot);

        if(i < j) swap(arr[i], arr[j]);
    } while(i < j);

    swap(arr[l], arr[j]);

    return j;
}

void quickSort(int arr[], int l, int h) {
    int j;
    if(l < h) {
        j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j+1, h);
    }
}

int main() {
    int size;
    cout << "Size of the array: ";
    cin >> size;
    int max = 0;
    int* array = new int[size+1];
    for(int i = 0; i < size; i++) {
        cout << "Enter " << ((i==0) ? "the first " : "the next") << " element: ";
        cin >> array[i];
        max += array[i];
    }
    array[size] = max + 1; 
    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
    cout << "\nSorted by Quick sort: ";
    quickSort(array,0, size);
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}