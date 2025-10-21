#include <iostream>
using namespace std;

int binarySearchIteratively(int array[], int size, int num) {
    int low = 0, high = size -1, mid;
    while(low <= high) {
        mid = (low+high)/2;
        if(num == array[mid]) {
            return mid;
        } else if (num < array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursively(int array[], int size, int num, int low, int high) {    
    if(low <= high) {
        int mid = (low + high)/2;
        if(num == array[mid]) {
            return mid;
        } else if(num < array[mid]) {
            return binarySearchRecursively(array, size, num, low, mid - 1);
        } else {
            return binarySearchRecursively(array, size, num, mid + 1, high);
        }
        
    }
    return -1;
}


int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, num;
    cout << "Enter the element you want to find the index of: " << endl;
    cin >> num;
    cout << "Found iteratively to be: ";
    cout << binarySearchIteratively(array, size, num) << endl;

    cout << "Found recursively to be: ";
    cout << binarySearchRecursively(array, size, num, 0, size-1) << endl;

    return 0;
}