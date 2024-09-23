#include <iostream>
#include <string>

using namespace std;

void printCharCount(string s) {
    int n = s.length();
    bool counted[256] = {false}; // To check if a character is already counted

    // Outer loop to go through each character in the string
    for (int i = 0; i < n; i++) {
        // If the character has already been counted, skip it
        if (counted[s[i]]) {
            continue;
        }

        // Count the occurrences of the current character
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (s[i] == s[j]) {
                count++;
            }
        }

        // Mark this character as counted
        counted[s[i]] = true;

        // Print the character and its count
        cout << s[i] << ": " << count << endl;
    }
}

int main() {

    string s;
    cin >> s;
    printCharCount(s);
    
    return 0;
}
