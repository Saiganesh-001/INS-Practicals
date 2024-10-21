#include <iostream>
#include <string>

using namespace std;

// Function to encrypt the message
void Encrypt(string inputText, int shift) {
    for (char &s : inputText) {
        if (isalpha(s)) {
            if (s < 'a') { 
                s += shift;
                if (s > 'Z')
                    s -= 26;
            } else { 
                s += shift;
                if (s > 'z')
                    s -= 26;
            }
        }
    }
    cout << "The encoded message is: " << inputText << "\n";
}

// Function to decrypt the message
void Decrypt(string inputText, int shift) {
    for (char &s : inputText) {
        if (isalpha(s)) {
            if (s < 'a') { 
                s -= shift;
                if (s < 'A')
                    s += 26;
            } else { 
                s -= shift;
                if (s < 'a')
                    s += 26;
            }
        }
    }
    cout << "The decoded message is: " << inputText << "\n";
}

int main() {
    string inputText;
    int shift, code;

    cout << "Type the message: ";
    cin >> inputText;
    cout << "Enter the number of shifts: ";
    cin >> shift;
    cout << "Type 1 to encrypt or 2 to decrypt: ";
    cin >> code;

    if (code != 1 && code != 2) {
        cout << "Invalid input\n";
    } else if (code == 1) {
        Encrypt(inputText, shift);
    } else {
        Decrypt(inputText, shift);
    }

    return 0;
}
