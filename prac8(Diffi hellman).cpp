#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// Function to check if x is a primitive root modulo q
bool isPrimitiveRoot(int x, int q) {
    set<int> powers;
    for (int i = 1; i < q; ++i) {
        int power = (int)pow(x, i) % q;
        if (powers.find(power) != powers.end()) {
            return false; 
        }
        powers.insert(power);
    }
    return powers.size() == q - 1; 
}

// Function to perform modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod; 
        }
        base = (base * base) % mod; 
        exp /= 2; 
    }
    return result;
}

int main() {
    int q, x, xa, xb;

    cout << "Enter value for q: ";
    cin >> q;

    do {
        cout << "Enter value for x (primitive root of q): ";
        cin >> x;
    } while (!isPrimitiveRoot(x, q));

    cout << "Enter private key for Alice (xa): ";
    cin >> xa;

    cout << "Enter private key for Bob (xb): ";
    cin >> xb;

    int ya = modExp(x, xa, q); // Compute Alice's public key
    int yb = modExp(x, xb, q); // Compute Bob's public key

    int ka = modExp(yb, xa, q); // Compute shared secret key for Alice
    int kb = modExp(ya, xb, q); // Compute shared secret key for Bob

    cout << "Key A: " << ka << endl; // Display Alice's key
    cout << "Key B: " << kb << endl; // Display Bob's key

    return 0;
}
