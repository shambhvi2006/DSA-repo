#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmallerToLeft(const vector<int>& arr) {
    stack<int> s;  
    vector<int> result;
    
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            result.push_back(-1); 
        } else {
            result.push_back(s.top());  
        }

        s.push(arr[i]); 
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> res = nearestSmallerToLeft(arr);

    cout << "Nearest smaller elements to the left are:\n";
    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}
