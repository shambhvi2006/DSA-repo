// Sort an array of 0s, 1s and 2s - Dutch National Flag Problem
// Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e.,
// put all 0s first, then all 1s and all 2s in last.

#include <iostream>
using namespace std;

int main(){
    int low, mid, high;
    low = 0;
    mid = 0;
    high = 5;
    int arr[] = {0, 1, 2, 0, 1, 2};
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else if (arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}