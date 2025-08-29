#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), ans(n, -1);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> st; // store values
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i]) st.pop();
        if (!st.empty()) ans[i] = st.top();
        st.push(a[i]);
    }

    for (int i = 0; i < n; i++) cout << ans[i] << (i+1<n?' ':'\n');
    return 0;
}
