#include <iostream>
#include <vector>
using namespace std;

class MinStack {
    vector<int> st;
    int minVal;
public:
    MinStack(): minVal(0) {}

    void push(int x) {
        if (st.empty()) { st.push_back(x); minVal = x; }
        else if (x >= minVal) st.push_back(x);
        else { st.push_back(2*x - minVal); minVal = x; }
    }

    void pop() {
        if (st.empty()) return;
        int t = st.back(); st.pop_back();
        if (t < minVal) { // marker: restore previous min
            minVal = 2*minVal - t;
        }
    }

    int top() const {
        int t = st.back();
        return (t >= minVal) ? t : minVal;
    }

    int getMin() const { return minVal; }

    bool empty() const { return st.empty(); }
};

int main() {
    MinStack ms;
    ms.push(3); ms.push(5); cout << ms.getMin() << "\n"; // 3
    ms.push(2); cout << ms.getMin() << "\n";             // 2
    ms.push(1); cout << ms.getMin() << "\n";             // 1
    cout << ms.top() << "\n";                            // 1
    ms.pop();  cout << ms.getMin() << "\n";              // 2
    ms.pop();  cout << ms.getMin() << "\n";              // 3
    return 0;
}
