#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;  // Error code
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 4:
                cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                val = s.peek();
                if (val != -1)
                    cout << "Top element is: " << val << endl;
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 7);

    return 0;
}
