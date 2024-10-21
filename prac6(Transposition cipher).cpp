#include <bits/stdc++.h>
using namespace std;

// Function for Encryption
string Encryption(int no_rows, int len_key, int len_msg, string msg, int col_val[]) {
    int x = 0;
    char enc_mat[no_rows + 1][len_key];

    for (int i = 0; i < no_rows + 1; i++) {
        for (int j = 0; j < len_key; j++) {
            if (x >= len_msg) {
                enc_mat[i][j] = '\0'; 
            } else {
                enc_mat[i][j] = msg[x];
                x++;
            }
        }
    }

    string cipher = "";
    // Read columns based on the column values (key order)
    for (int t = 1; t <= len_key; t++) {
        for (int i = 0; i < len_key; i++) {
            int k = col_val[i];
            if (k == t) {
                for (int j = 0; j < no_rows + 1; j++) {
                    if (enc_mat[j][i] != '\0') { 
                        cipher += enc_mat[j][i];
                    }
                }
            }
        }
    }

    return cipher;
}

// Function for Decryption
string Decryption(int no_rows, int len_key, string cipher, int col_val[]) {
    char dec_mat[no_rows + 1][len_key];
    int x = 0;

    // Fill the matrix with the cipher text
    for (int t = 1; t <= len_key; t++) {
        for (int i = 0; i < len_key; i++) {
            int k = col_val[i];
            if (k == t) {
                for (int j = 0; j < no_rows + 1; j++) {
                    if (x < cipher.length()) {
                        dec_mat[j][i] = cipher[x];
                        x++;
                    } else {
                        dec_mat[j][i] = '\0'; 
                    }
                }
            }
        }
    }

    // Read the matrix row-wise to get the original message
    string message = "";
    for (int i = 0; i < no_rows + 1; i++) {
        for (int j = 0; j < len_key; j++) {
            if (dec_mat[i][j] != '\0') { 
                message += dec_mat[i][j];
            }
        }
    }

    return message;
}

int main() {
    string msg, key;
    int choice;

    cout << "Enter the message: ";
    getline(cin, msg);

    cout << "Enter the key: ";
    cin >> key;

    int len_key = key.length();
    int len_msg = msg.length();
    int val = 1, count = 0, ind;
    int col_val[len_key];
    memset(col_val, 0, sizeof(col_val));

    // Generate column order based on the alphabetical order of the key
    while (count < len_key) {
        int min = 999;
        for (int i = 0; i < len_key; i++) {
            if ((min > int(key[i])) && (col_val[i] == 0)) {
                min = int(key[i]);
                ind = i;
            }
        }
        col_val[ind] = val;
        count++;
        val++;
    }

    int no_rows = len_msg / len_key;

    cout << "Choose operation:\n1. Encrypt\n2. Decrypt\n";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            string cipher_text = Encryption(no_rows, len_key, len_msg, msg, col_val);
            cout << "Encrypted Message: " << cipher_text << endl;
            break;
        }
        case 2: {
            string cipher_text;
            cout << "Enter the cipher text: ";
            getline(cin, cipher_text);
            string original_msg = Decryption(no_rows, len_key, cipher_text, col_val);
            cout << "Decrypted Message: " << original_msg << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
