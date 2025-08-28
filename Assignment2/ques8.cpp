#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    int distinct = 0;
    for (int i = 0; i < n; ++i) {
        bool seen_before = false;
        for (int j = 0; j < i; ++j) {
            if (a[j] == a[i]) { 
                seen_before = true; 
                break; 
            }
        }
        if (!seen_before) ++distinct;
    }

    cout << distinct << "\n";
    delete[] a;
    return 0;
}
