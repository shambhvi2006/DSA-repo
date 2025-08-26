#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


bool checkBalanced(const string &expr) {
    stack<char> st;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;       
            char open = st.top();
            st.pop();
            if (!isMatching(open, c)) return false; 
        }
    }
    return st.empty(); 
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (checkBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

   return 0;
}