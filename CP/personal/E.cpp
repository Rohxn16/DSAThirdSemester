#include <iostream>
using namespace std;

int main() {
    // Print the letter pattern
    for (int row = 0; row < 4; row++) { // Loop for each row (0 to 3)
        // Print letters in decreasing count for each row
        for (int col = 0; col < 4 - row; col++) { // Number of letters decreases as the row increases
            cout << char('A' + row); // Convert row index to the corresponding letter
        }
        cout << endl; // Move to the next line after each row
    }

    cout << endl; // Print a new line for separation

    // Print the number pattern
    for (int row = 0; row < 4; row++) { // Loop for each row (0 to 3)
        // Print increasing numbers for each row
        for (int num = 0; num <= row; num++) { // Numbers start from 0 and go up to the current row index
            cout << num << " "; // Print the number followed by a space
        }
        cout << endl; // Move to the next line after each row
    }

    return 0;
}
