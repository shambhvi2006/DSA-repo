#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);

    stack<char> s;

    for (char c : str) {
        s.push(c);
    }

    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
