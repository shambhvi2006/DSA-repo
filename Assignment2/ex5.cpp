// Given a fixed-length integer array arr, duplicate each occurrence of two (2), shifting the
// remaining elements to the right.
// Note that elements beyond the length of the original array are not written. Do the above
// modifications to the input array in place and do not return anything.

#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }
    int newSize = n + count;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 1) {
            arr[newSize - 1] = 1;
            newSize--;
        }
        arr[newSize - 1] = arr[i];
        newSize--;
    }
}

int main() {
    int arr[6] = {0, 1, 2, 0, 1, 2};
    duplicateTwos(arr, 6);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
