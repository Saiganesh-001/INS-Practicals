#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

// Function to create a cipher key from user input
unordered_map<char, char> createCipherKey(const string& cipherAlphabet) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    unordered_map<char, char> cipherKey;
    for (size_t i = 0; i < alphabet.size(); ++i) {
        cipherKey[alphabet[i]] = cipherAlphabet[i];
    }
    return cipherKey;
}

// Function to create a decryption key (inverse of cipher key)
unordered_map<char, char> createDecryptionKey(const unordered_map<char, char>& cipherKey) {
    unordered_map<char, char> decryptionKey;
    for (auto& pair : cipherKey) {
        decryptionKey[pair.second] = pair.first;
    }
    return decryptionKey;
}

// Function to encrypt the plaintext using the cipher key
string encrypt(const string& plaintext, const unordered_map<char, char>& cipherKey) {
    string encryptedText = "";
    for (char ch : plaintext) {
        char lowerChar = tolower(ch);
        if (cipherKey.find(lowerChar) != cipherKey.end()) {
            encryptedText += cipherKey.at(lowerChar);
        } else {
            encryptedText += ch; 
        }
    }
    return encryptedText;
}

// Function to decrypt the ciphertext using the decryption key
string decrypt(const string& ciphertext, const unordered_map<char, char>& decryptionKey) {
    string decryptedText = "";
    for (char ch : ciphertext) {
        char lowerChar = tolower(ch); 
        if (decryptionKey.find(lowerChar) != decryptionKey.end()) {
            decryptedText += decryptionKey.at(lowerChar);
        } else {
            decryptedText += ch; 
        }
    }
    return decryptedText;
}

int main() {
    string plaintext, ciphertext, cipherAlphabet;
    int choice;

    // User input for cipher alphabet
    cout << "Enter a 26-character cipher alphabet (e.g., 'zyxwvutsrqponmlkjihgfedcba'): ";
    getline(cin, cipherAlphabet);

 
    if (cipherAlphabet.length() != 26) {
        cout << "Error: The cipher alphabet must contain exactly 26 characters." << endl;
        return 1;
    }

    // Create encryption and decryption keys
    unordered_map<char, char> cipherKey = createCipherKey(cipherAlphabet);
    unordered_map<char, char> decryptionKey = createDecryptionKey(cipherKey);

    cout << "Choose an option: \n1. Encrypt \n2. Decrypt\n";
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        cout << "Enter the plaintext: ";
        getline(cin, plaintext);
        ciphertext = encrypt(plaintext, cipherKey);
        cout << "Encrypted text: " << ciphertext << endl;
    } else if (choice == 2) {
        cout << "Enter the ciphertext: ";
        getline(cin, ciphertext);
        plaintext = decrypt(ciphertext, decryptionKey);
        cout << "Decrypted text: " << plaintext << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
