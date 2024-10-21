#include <iostream>
#include <string>
using namespace std;

// Function to generate the key matrix for encryption
void getKeyMatrix(string key, int keyMatrix[3][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

// Function to encrypt the message
void encrypt(int cipherMatrix[3][1], int keyMatrix[3][3], int messageVector[3][1]) {
    for (int i = 0; i < 3; i++) {
        cipherMatrix[i][0] = 0;
        for (int j = 0; j < 3; j++) {
            cipherMatrix[i][0] += keyMatrix[i][j] * messageVector[j][0];
        }
        cipherMatrix[i][0] = cipherMatrix[i][0] % 26;
    }
}

// Function to perform Hill Cipher encryption
void HillCipher(string message, string key) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int messageVector[3][1];
    for (int i = 0; i < 3; i++) {
        messageVector[i][0] = (message[i]) % 65;
    }

    int cipherMatrix[3][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);

    string CipherText;
    for (int i = 0; i < 3; i++) {
        CipherText += cipherMatrix[i][0] + 65;
    }

    cout << "Ciphertext: " << CipherText << endl;
}

int main() {
    string message;
    string key;
    int choice;

    cout << "Enter the message (3 characters): ";
    cin >> message;

    cout << "Enter the key (9 characters): ";
    cin >> key;

    cout << "Choose operation:\n1. Encrypt\n2. Decrypt\n";
    cin >> choice;

    switch (choice) {
        case 1:
            HillCipher(message, key);
            break;
        case 2:
            cout << "Decryption functionality is not implemented in this example." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
