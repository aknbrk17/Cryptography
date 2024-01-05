#include <iostream>
#include <string>

using namespace std;

string encryptVigenereCipher(const string& plainText, const string& key) {
    string cipherText = "";
    int keyLength = key.length();
    
    for (int i = 0, j = 0; i < plainText.length(); ++i) {
        char ch = plainText[i];
        
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyChar = key[j % keyLength];
            char encryptedChar = static_cast<char>((ch - base + keyChar - 'A') % 26 + base);
            
            cipherText += encryptedChar;
            ++j;
        } else {
            cipherText += ch;
        }
    }
    
    return cipherText;
}

string decryptVigenereCipher(const string& cipherText, const string& key) {
    string plainText = "";
    int keyLength = key.length();
    
    for (int i = 0, j = 0; i < cipherText.length(); ++i) {
        char ch = cipherText[i];
        
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyChar = key[j % keyLength];
            char decryptedChar = static_cast<char>((ch - base - keyChar + 'A' + 26) % 26 + base);
            
            plainText += decryptedChar;
            ++j;
        } else {
            plainText += ch;
        }
    }
    
    return plainText;
}

int main() {
    string plainText, key;

    cout << "Metni girin: ";
    getline(cin, plainText);

    cout << "Anahtar kelimeyi girin: ";
    getline(cin, key);

    string encryptedText = encryptVigenereCipher(plainText, key);
    cout << "Şifrelenmiş Metin: " << encryptedText << endl;

    string decryptedText = decryptVigenereCipher(encryptedText, key);
    cout << "Deşifre Edilmiş Metin: " << decryptedText << endl;

    return 0;
}
