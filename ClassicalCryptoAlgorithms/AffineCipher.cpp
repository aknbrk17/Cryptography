#include <iostream>
#include <string>

using namespace std;

string encryptAffineCipher(const string& plainText , int key[]){
    string cipherText = "";
    for(char ch : plainText){
        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';
            cipherText += static_cast<char>(((ch-base)*key[0] + key[1]) % 26 + base);
        }else{
            cipherText += ch;
        }
    }
    return cipherText;
}

int modInverse(int a , int m){
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}


string decryptAffineCipher(const string& ciphertext, int key[]) {
    int aInverse = modInverse(key[0], 26);
    string plaintext = "";
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            plaintext += static_cast<char>(aInverse * (ch - base - key[1] + 26) % 26 + base);
        } else {
            plaintext += ch;
        }
    }
    return plaintext;
}


int main(int argc, const char * argv[]) {
    
    string plainText;
    int key[2];
    
    cout << "Metni giriniz : ";
    getline(cin , plainText);
    
    cout << "Anahtarın ilk elemanını giriniz : ";
    cin >> key[0];
    
    cout << "Anahtarın diğer elemanını giriniz : ";
    cin >> key[1];
    
    string encryptedText = encryptAffineCipher(plainText, key);
    cout<< "Şifrelenmiş Metin: " << encryptedText << endl;
    
    string decryptedText = decryptAffineCipher(encryptedText, key);
    cout << "Deşifre Edilmiş Metin: " << decryptedText << endl;
    
    return 0;
}
