#include <iostream>
using namespace std;

long long mergeAndCount(long long arr[], long long temp[], int l, int m, int r) {
    int i=l, j=m+1, k=l;
    long long inv=0;
    while (i<=m && j<=r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (m - i + 1); // all remaining in left are greater than arr[j-1]
        }
    }
    while (i<=m) temp[k++] = arr[i++];
    while (j<=r) temp[k++] = arr[j++];
    for (int p=l; p<=r; ++p) arr[p] = temp[p];
    return inv;
}

long long sortAndCount(long long arr[], long long temp[], int l, int r) {
    if (l>=r) return 0;
    int m = (l+r)/2;
    long long inv = 0;
    inv += sortAndCount(arr, temp, l, m);
    inv += sortAndCount(arr, temp, m+1, r);
    inv += mergeAndCount(arr, temp, l, m, r);
    return inv;
}

int main() {
    int n; cin >> n;
    long long* a = new long long[n];
    for (int i=0;i<n;++i) cin >> a[i];
    long long* tmp = new long long[n];
    cout << sortAndCount(a, tmp, 0, n-1) << "\n";
    delete[] a; delete[] tmp;
    return 0;
}
