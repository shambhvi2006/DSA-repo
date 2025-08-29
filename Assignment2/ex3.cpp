// String Anagrams
// Given two strings str1 and str2, determine if they form an anagram pair.
// Note: Two strings are considered anagrams if one string can be rearranged to form the other
// string.

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    unordered_map<char, int> freq;

    for (char c : str1) {
        freq[c]++;
    }

    for (char c : str2) {
        freq[c]--;
    }

    bool isAnagram = true;
    for (auto i : freq) {
        if (i.second != 0) {
            isAnagram = false;
            break;
        }
    }

    if (isAnagram) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}