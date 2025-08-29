// String Split Challenge
// You are given a string consisting of lowercase English alphabets. Your task is to determine if
// it's possible to split this string into three non-empty parts (substrings) where one of these
// parts is a substring of both remaining parts
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;                          // read the string
    int n = (int)s.size();
    if (n < 3) {                       // need 3 non-empty parts at least
        cout << "NO\n";
        return 0;
    }

    int cnt[26] = {0};                 // frequency of each lowercase letter
    for (char ch : s) cnt[ch - 'a']++; // O(n) count

    int c = -1;                        // find any letter that appears >= 3 times
    for (int k = 0; k < 26; ++k)
        if (cnt[k] >= 3) { c = k; break; }

    if (c == -1) {                     // none found -> impossible
        cout << "NO\n";
        return 0;
    }

    char target = char('a' + c);
    int seen = 0, mid = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == target && ++seen == 2) { mid = i; break; }
    }

    // split at the 2nd occurrence: S1 | S2 | S3
    string S1 = s.substr(0, mid);      // all before the 2nd occurrence
    string S2 = s.substr(mid, 1);      // the single character (2nd occurrence)
    string S3 = s.substr(mid + 1);     // all after it

    cout << "YES\n";
    cout << S1 << "\n" << S2 << "\n" << S3 << "\n";
    return 0;
}
