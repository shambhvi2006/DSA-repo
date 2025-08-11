#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (sorted for binary search):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the element to search: ";
    cin >> key;

    
    int indexLinear = linearSearch(arr, n, key);
    if (indexLinear != -1)
        cout << "Linear Search: Element found at index " << indexLinear << endl;
    else
        cout << "Linear Search: Element not found.\n";

    
    int indexBinary = binarySearch(arr, n, key);
    if (indexBinary != -1)
        cout << "Binary Search: Element found at index " << indexBinary << endl;
    else
        cout << "Binary Search: Element not found.\n";

    return 0;
}
