#include <iostream>
#include <string>

using namespace std;

struct BankAccount {
    string name;
    string address;
    string panNumber;
    string aadhaarNumber;
    double currentBalance;
    int addressUpdateCount;

    // Constructor to initialize the account with mandatory details
    BankAccount(string accName, string pan, string aadhaar, string addr = "")
        : name(accName), panNumber(pan), aadhaarNumber(aadhaar), address(addr), currentBalance(0.0), addressUpdateCount(0) {}

    // Function to deposit money
    void depositMoney(double amount) {
        currentBalance += amount;
        cout << "Amount deposited: " << amount << endl;
        cout << "Updated balance: " << currentBalance << endl;
    }

    // Function to check account balance
    void checkBalance() const {
        cout << "Current balance: " << currentBalance << endl;
    }

    // Function to display account details
    void displayAccountDetails() const {
        cout << "Account Holder's Name: " << name << endl;
        cout << "PAN Number: " << panNumber << endl;
        cout << "Aadhaar Number: " << aadhaarNumber << endl;
        cout << "Address: " << (address.empty() ? "Not provided" : address) << endl;
        cout << "Current Balance: " << currentBalance << endl;
    }

    // Function to update address
    void updateAddress(const string& newAddress) {
        if (addressUpdateCount < 3) {
            address = newAddress;
            addressUpdateCount++;
            cout << "Address updated successfully." << endl;
        } else {
            cout << "Address update limit reached." << endl;
        }
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Display Account Details\n";
    cout << "2. Deposit Money\n";
    cout << "3. Check Balance\n";
    cout << "4. Update Address\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    // Creating a new bank account
    string name, pan,aadhar,address;
    cout << "Enter name:\n";
    getline(cin, name);
    cout << "Enter PAN, AADHAR separated by newline\n";
    cin >> pan >> aadhar;
    BankAccount account(name,pan,aadhar,address);

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                account.displayAccountDetails();
                break;
            case 2: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.depositMoney(amount);
                break;
            }
            case 3:
                account.checkBalance();
                break;
            case 4: {
                string newAddress;
                cout << "Enter new address: ";
                cin.ignore(); // To clear the newline character from the input buffer
                getline(cin, newAddress);
                account.updateAddress(newAddress);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}