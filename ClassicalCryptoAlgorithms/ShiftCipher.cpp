#include <iostream>
#include <string>
using namespace std;

string encrypShiftCipher(const string& plainText , int key){
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

string decryptShiftCipher(const string& cipherText , int key){
    return encrypShiftCipher(cipherText , 26-key);
}

int main(int argc, const char * argv[]) {
    string text;
    int key;
    
    cout<<"Metni girin : ";
    getline(cin , text);
    
    cout<<"Anahtarı girin : ";
    cin>>key;
    
    string encryptedText = encrypShiftCipher(text, key);
    cout<<"Şifrelenmiş metin : "<<encryptedText<<endl;
    
    string decryptedText = decryptShiftCipher(encryptedText, key);
    cout<<"Deşifre edilmiş metin : "<<decryptedText<<endl;
    
    return 0;
    
}