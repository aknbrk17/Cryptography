#include <iostream>
#include <string>
using namespace std;

string encrypAutokeyCipher(const string& plainText , int key){
    string cipherText = "";
    for(char ch : plainText) {
        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';
            cipherText += static_cast<char>((ch - base + key) % 26 + base);

        } else{
            cipherText += ch;
        }
    }
    return cipherText;
}

string decryptAutokeyCipher(const string& cipherText , int key){
    return encrypAutokeyCipher(cipherText , 26-key);
}

int main(int argc, const char * argv[]) {
    string text;
    int key;
    
    cout<<"Metni girin : ";
    getline(cin , text);
    
    cout<<"Anahtarı girin : ";
    cin>>key;
    
    string encryptedText = encrypAutokeyCipher(text, key);
    cout<<"Şifrelenmiş metin : "<<encryptedText<<endl;
    
    string decryptedText = decryptAutokeyCipher(encryptedText, key);
    cout<<"Deşifre edilmiş metin : "<<decryptedText<<endl;
    
    return 0;
    
}