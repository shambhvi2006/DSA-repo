#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), ans(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    stack<int> st; // store values
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() >= a[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(a[i]);
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << (i+1<n?' ':'\n');
    return 0;
}
