#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    int inv = 0;                           // can be up to n*(n-1)/2
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j]) ++inv;

    cout << inv << "\n";
    delete[] a;
    return 0;
}
