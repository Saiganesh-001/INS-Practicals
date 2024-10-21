#include <iostream>
using namespace std;

// Function to encrypt the plain text
string convertPlainTextToCipherText(string plainText, string key) {
    int textSize = plainText.size();
    int keySize = key.size();
    int i = 0;
    string ans = "";

    for (int j = 0; j < textSize; j++) {
        ans += ('a' + ((plainText[j] - 'a' + key[i] - 'a') % 26));
        i = (i + 1) % keySize; 
    }

    return ans;
}

// Function to decrypt the cipher text
string convertCipherTextToPlainText(string cipherText, string key) {
    int textSize = cipherText.size();
    int keySize = key.size();
    int i = 0;
    string ans = "";

    for (int j = 0; j < textSize; j++) {
        ans += ('a' + ((cipherText[j] - 'a' - (key[i] - 'a') + 26) % 26));
        i = (i + 1) % keySize; 
    }

    return ans;
}

int main() {
    string plainText, key;
    int choice;

    cout << "Enter 1 for Encryption or 2 for Decryption: ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        cout << "Enter plain text: ";
        getline(cin, plainText);
        cout << "Enter key: ";
        getline(cin, key);
        string cipherText = convertPlainTextToCipherText(plainText, key);
        cout << "Cipher Text: " << cipherText << endl;
    } else if (choice == 2) {
        cout << "Enter cipher text: ";
        getline(cin, plainText); 
        cout << "Enter key: ";
        getline(cin, key);
        string decryptedText = convertCipherTextToPlainText(plainText, key);
        cout << "Plain Text: " << decryptedText << endl;
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
