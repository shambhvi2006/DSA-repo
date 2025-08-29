#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    vector<int> C = A; sort(C.begin(), C.end()); // target ascending sequence
    stack<int> S;
    int j = 0; // next needed in C

    for (int x : A) {
        S.push(x);
        while (!S.empty() && S.top() == C[j]) { S.pop(); ++j; }
    }
    while (!S.empty() && S.top() == C[j]) { S.pop(); ++j; }

    cout << (j == n ? "YES" : "NO") << "\n";
    return 0;
}
