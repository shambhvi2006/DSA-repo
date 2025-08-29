#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> T(n), ans(n,0);
    for (int i = 0; i < n; ++i) cin >> T[i];

    stack<int> st; // indices with decreasing T
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && T[i] > T[st.top()]) {
            int j = st.top(); st.pop();
            ans[j] = i - j;
        }
        st.push(i);
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << (i+1<n?' ':'\n');
    return 0;
}
