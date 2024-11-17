#include <iostream>
#include <string>

using namespace std;

class Ceasercypher {
public:
    void encrypt(string& message, int shift);
    void decrypt(string& encryptedMessage, int shift);
};

void Ceasercypher::encrypt(string& message, int shift) {
    for (char& ch : message) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = base + (ch - base + shift) % 26;
        }
    }
}

void Ceasercypher::decrypt(string& encryptedMessage, int shift) {
    encrypt(encryptedMessage, -shift); 
}

int main() {
    Ceasercypher cipher;

    string message;
    int shift;

    cout << "Enter message to encrypt: ";
    getline(cin, message);

    cout << "Enter shift value (integer): ";
    cin >> shift;

    cipher.encrypt(message, shift);
    cout << "Encrypted message: " << message << endl;

    cipher.decrypt(message, shift);
    cout << "Decrypted message: " << message << endl;

    return 0;
}