#include <bits/stdc++.h>
using namespace std;

// Function to generate a random key of specified length
string generateRandomKey(int length) {
    string key = "";
    for (int i = 0; i < length; i++) {
        char randomChar = 'A' + rand() % 26; 
        key += randomChar;
    }
    return key;
}

// Function to encrypt the plaintext using the key
string encrypt(const string& plaintext, const string& key) {
    string ciphertext = "";
    for (size_t i = 0; i < plaintext.length(); i++) {
        char p = toupper(plaintext[i]); 
        char k = toupper(key[i]); 

        // Encrypt character
        char c = ((p - 'A') + (k - 'A')) % 26 + 'A';
        ciphertext += c;
    }
    return ciphertext;
}

// Function to decrypt the ciphertext using the key
string decrypt(const string& ciphertext, const string& key) {
    string plaintext = "";
    for (size_t i = 0; i < ciphertext.length(); i++) {
        char c = toupper(ciphertext[i]); 
        char k = toupper(key[i]); 

        // Decrypt character
        char p = ((c - 'A') - (k - 'A') + 26) % 26 + 'A';
        plaintext += p;
    }
    return plaintext;
}

int main() {
    srand(time(0)); 

    string plaintext, key, ciphertext;

    cout << "Enter the plaintext (A-Z only): ";
    getline(cin, plaintext);

    cout << "Enter the key (A-Z only): ";
    getline(cin, key);

    // Check if the key length matches the plaintext length
    if (plaintext.length() != key.length()) {
        cout << "Warning. Key length does not match plaintext length. Generating a random key.\n";
        key = generateRandomKey(plaintext.length());
        cout << "Generated key: " << key << endl;
    }

    // Encrypt the plaintext using the key
    ciphertext = encrypt(plaintext, key);
    cout << "Encrypted text: " << ciphertext << endl;

    // Decrypt the ciphertext back to plaintext
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
