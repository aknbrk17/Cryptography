#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Permütasyon Şifreleme Fonksiyonu
string encryptPermutationCipher(const string& plaintext, const vector<int>& permutation) {
    int length = plaintext.length();
    int numRows = (length + permutation.size() - 1) / permutation.size();

    // Metni bir matrise yerleştirme
    vector<vector<char> > matrix(numRows, vector<char>(permutation.size(), ' '));
    int index = 0;

    for (int col : permutation) {
        for (int row = 0; row < numRows; ++row) {
            if (index < length) {
                matrix[row][col] = plaintext[index++];
            }
        }
    }

    // Matristeki karakterleri okuma
    string ciphertext = "";
    for (int row = 0; row < numRows; ++row) {
        for (int col : permutation) {
            if (matrix[row][col] != ' ') {
                ciphertext += matrix[row][col];
            }
        }
    }

    return ciphertext;
}

// Permütasyon Deşifreleme Fonksiyonu
string decryptPermutationCipher(const string& ciphertext, const vector<int>& permutation) {
    int length = ciphertext.length();
    int numRows = (length + permutation.size() - 1) / permutation.size();

    // Metni bir matrise yerleştirme
    vector<vector<char> > matrix(numRows, vector<char>(permutation.size(), ' '));
    int index = 0;

    // Matrise karakterleri yerleştirme
    for (int col : permutation) {
        for (int row = 0; row < numRows; ++row) {
            if (index < length) {
                matrix[row][col] = ciphertext[index++];
            }
        }
    }

    // Matristeki karakterleri okuma
    string plaintext = "";
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < permutation.size(); ++col) {
            if (matrix[row][col] != ' ') {
                plaintext += matrix[row][col];
            }
        }
    }

    return plaintext;
}

int main() {
    string text;
    vector<int> permutation;

    // Kullanıcıdan metin ve permütasyon vektörünü alma
    cout << "Metni girin: ";
    getline(cin, text);

    int length = text.length();
    permutation.resize(length);

    cout << "Permütasyon vektörünü girin (örneğin, 3 5 1 6 4 2): ";
    for (int i = 0; i < length; ++i) {
        cin >> permutation[i];
    }

    // Şifreleme
    string encryptedText = encryptPermutationCipher(text, permutation);
    cout << "Şifrelenmiş Metin: " << encryptedText << endl;

    // Deşifreleme
    string decryptedText = decryptPermutationCipher(encryptedText, permutation);
    cout << "Deşifre Edilmiş Metin: " << decryptedText << endl;

    return 0;
}
