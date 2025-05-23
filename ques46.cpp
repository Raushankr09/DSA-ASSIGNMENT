/* Write a program to find the longest palindromic substring in a given string. Write its 
algorithm, program. Find its time and space complexities. Explain with suitable 
example.*/

#include <iostream>
#include <string>
using namespace std;

string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";

    string longest = "";
    for (int i = 0; i < s.length(); i++) {
        // Odd length palindrome
        string odd = expandAroundCenter(s, i, i);

        // Even length palindrome
        string even = expandAroundCenter(s, i, i + 1);

        // Update longest if necessary
        if (odd.length() > longest.length()) {
            longest = odd;
        }
        if (even.length() > longest.length()) {
            longest = even;
        }
    }
    return longest;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}
