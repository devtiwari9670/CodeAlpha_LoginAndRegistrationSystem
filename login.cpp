#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Function to check if username already exists
bool userExists(const string &username) {
    ifstream file("users.txt");
    string line, storedUser, storedPass;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> storedUser >> storedPass;
        if (storedUser == username) {
            return true;
        }
    }
    return false;
}

// Registration function
void registerUser() {
    string username, password;

    cout << "\n=== User Registration ===\n";
    cout << "Enter username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Error: Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password, storedUser, storedPass;

    cout << "\n=== User Login ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    bool success = false;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            success = true;
            break;
        }
    }
    file.close();

    if (success) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Error: Invalid username or password.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
