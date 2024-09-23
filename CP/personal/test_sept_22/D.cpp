#include <iostream>
#include <string>

using namespace std;

// checking for string equality with custom functionl 
bool isEqualString(const string& a, const string& b) {
    // checking for length equality
    if (a.length() != b.length()) {
        return false;
    }
    // matching character by character in case the length is same
    for (size_t i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() { // main method
    string str1;
    string str2;
    cin >> str1 >> str2;

    if(isEqualString(str1, str2)) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    return 0;
}