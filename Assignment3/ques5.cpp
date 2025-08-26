#include <iostream>
#include <stack>
#include <string>
using namespace std;

int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; 
        default:
            cout << "Unknown operator: " << op << endl;
            return 0;
    }
}

int evaluatePostfix(const string& postfix) {
    stack<int> s;
    int n = postfix.size();
    for (int i = 0; i < n; ) {
        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(postfix[i])) {
            int num = 0;
            while (i < n && isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            
            }
            s.push(num);
        } else {
            if (s.size() < 2) {
                cout << "Invalid expression!" << endl;
                return 0;
            }
            int val2 = s.top(); 
            s.pop();
            int val1 = s.top(); 
            s.pop();

            int result = applyOp(val1, val2, postfix[i]);
            s.push(result);
            i++;
        }
    }

    if (s.size() != 1) {
        cout << "Invalid postfix expression!" << endl;
        return 0;
    }
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (tokens separated by spaces): ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
