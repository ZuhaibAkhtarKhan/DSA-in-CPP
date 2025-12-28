#include <iostream>
#include <algorithm>
using namespace std;

// int* merge(int arr1[], int arr2[], int m, int n) {
//     int* mergedArray = new int[m+n];
//     int i = 0, j = 0, k = 0;
//     while(i < m && j < n) {
//         if(arr1[i] < arr2[j]) {
//             mergedArray[k] = arr1[i];
//             i++;
//         } else {
//             mergedArray[k] = arr2[j];
//             j++;
//         }
//         k++;
//     }

//     while(i < m) {
//         mergedArray[k] = arr1[i];
//         i++;
//         k++;
//     }
//     while(j < n) {
//         mergedArray[k] = arr1[j];
//         j++;
//         k++;
//     }

//     return mergedArray;
// }

void merge(int arr[], int l,int mid, int h) {
    int size = h-l +1;
    int* mergedArray = new int[size];
    int i = l, j = mid+1, k = 0;
    while(i <= mid && j <= h) {
        if(arr[i] < arr[j]) {
            mergedArray[k] = arr[i];
            i++;
        } else {
            mergedArray[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        mergedArray[k] = arr[i];
        i++;
        k++;
    }
    while(j <= h) {
        mergedArray[k] = arr[j];
        j++;
        k++;
    }

    for(int m = 0; m<size; m++) {
        arr[l+m] = mergedArray[m]; 
    }
    delete[] mergedArray;

}

void mergeSortIte(int arr[], int size) {
    // 1. Loop Condition: Continue as long as we are merging blocks smaller than total size
    //    We check if (i/2 < size) to ensure we merge the final uneven chunks.
    for(int i = 2; i/2 < size; i = i * 2) {

        for(int j = 0; j < size; j += i) {
            
            int l = j;
            
            // 2. Midpoint Logic: Must be based on the block size (i/2)
            //    This marks the end of the Left Block.
            int mid = l + (i/2) - 1; 

            // 3. End Logic: Clamp to the end of the array
            int h = min(j + i - 1, size - 1);

            // 4. Safety Check: Only merge if there is actually a second block
            //    (i.e., mid is not the last element)
            if(mid < h) {
                merge(arr, l, mid, h);
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
    
    cout << "\nSorted by Merge sort: ";
    mergeSortIte(array, size);
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}