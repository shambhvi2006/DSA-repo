#include <iostream>
#include <stack>
using namespace std;
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0; 
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for(char c : infix) {
        //agar character hai toh sidha postfix mein daal do
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        }
        //opening bracket
        else if(c == '(') {
            s.push(c);
        }
        //closing bracket mei top ko dalte raho tab tak daalo jab tak 
        // opening bracket na mil jaye and then opening bracket nikal lo

        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); 
        }
        //operator daalo jab tak top wale ki precedence is less than current operator ki precedence
        else if(isOperator(c)) {
            while(!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
