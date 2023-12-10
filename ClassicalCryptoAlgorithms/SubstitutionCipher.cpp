#include <iostream>
#include <string>
#include <map>

using namespace std;

class SubstitutionCipher {
private:
    map<char, char> encryptionKey;
    map<char, char> decryptionKey;

public:
    void setEncryptionKey(const string& alphabet, const string& substitution) {
        if (alphabet.length() != substitution.length()) {
            cerr << "Hata: Anahtar uzunlukları eşleşmiyor." << endl;
            return;
        }

        encryptionKey.clear();
        decryptionKey.clear();

        for (size_t i = 0; i < alphabet.length(); ++i) {
            encryptionKey[alphabet[i]] = substitution[i];
            decryptionKey[substitution[i]] = alphabet[i];
        }
    }

    string encrypt(const string& plaintext) {
        string ciphertext = "";
        for (char ch : plaintext) {
            if (isalpha(ch)) {
                char base = isupper(ch) ? 'A' : 'a';
                ciphertext += encryptionKey[static_cast<char>(toupper(ch))];
            } else {
                ciphertext += ch;
            }
        }
        return ciphertext;
    }

    string decrypt(const string& ciphertext) {
        string plaintext = "";
        for (char ch : ciphertext) {
            if (isalpha(ch)) {
                plaintext += decryptionKey[static_cast<char>(toupper(ch))];
            } else {
                plaintext += ch;
            }
        }
        return plaintext;
    }
};

int main() {
    SubstitutionCipher cipher;

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string substitution = "";
    
    cout<<"π tablosunun değerlerini metin olarak giriniz : ";
    getline(cin , substitution);
    
    cipher.setEncryptionKey(alphabet, substitution);

    string plaintext;
    cout << "Metni girin: ";
    getline(cin, plaintext);

    string ciphertext = cipher.encrypt(plaintext);
    cout << "Şifrelenmiş Metin: " << ciphertext << endl;

    string decryptedText = cipher.decrypt(ciphertext);
    cout << "Deşifre Edilmiş Metin: " << decryptedText << endl;

    return 0;
}