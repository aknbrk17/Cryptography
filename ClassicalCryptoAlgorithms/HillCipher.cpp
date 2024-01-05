#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int determinant(const vector<vector<int> >& matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;
    for (int i = 0; i < n; ++i) {
        det += matrix[0][i] * (matrix[1][(i + 1) % n] * matrix[2][(i + 2) % n] - matrix[1][(i + 2) % n] * matrix[2][(i + 1) % n]);
    }

    return det;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

vector<vector<int> > transpose(const vector<vector<int> >& matrix, int n) {
    vector<vector<int> > result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

string encryptHillCipher(const string& plaintext, const vector<vector<int> >& keyMatrix) {
    int n = keyMatrix.size();
    int len = plaintext.length();

    vector<vector<int> > blocks;
    for (int i = 0; i < len; i += n) {
        vector<int> block;
        for (int j = i; j < i + n; ++j) {
            if (j < len) {
                block.push_back(plaintext[j] - 'A');
            } else {
                block.push_back(0); 
            }
        }
        blocks.push_back(block);
    }

    string ciphertext = "";
    for (const auto& block : blocks) {
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += keyMatrix[i][j] * block[j];
            }
            ciphertext += static_cast<char>((sum % 26) + 'A');
        }
    }

    return ciphertext;
}

string decryptHillCipher(const string& ciphertext, const vector<vector<int> >& keyMatrix) {
    int n = keyMatrix.size();
    int len = ciphertext.length();

    int det = determinant(keyMatrix, n);
    if (det == 0 || det % 2 == 0 || det % 13 == 0) {
        cerr << "Matrisin determinantı sıfır veya 2 veya 13 ile tam bölünebilir olmamalıdır." << endl;
        return "";
    }

    int detInverse = modInverse(det, 26);

    vector<vector<int> > keyMatrixInverse = transpose(keyMatrix, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            keyMatrixInverse[i][j] = (keyMatrixInverse[i][j] * detInverse) % 26;
        }
    }

    vector<vector<int> > blocks;
    for (int i = 0; i < len; i += n) {
        vector<int> block;
        for (int j = i; j < i + n; ++j) {
            block.push_back(ciphertext[j] - 'A');
        }
        blocks.push_back(block);
    }

    string plaintext = "";
    for (const auto& block : blocks) {
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += keyMatrixInverse[i][j] * block[j];
            }
            plaintext += static_cast<char>((sum % 26 + 26) % 26 + 'A');
        }
    }

    return plaintext;
}

int main() {
    string text;
    vector<vector<int> > keyMatrix;

    cout << "Metni girin (sadece büyük harf kullanın): ";
    getline(cin, text);

    cout << "Anahtar matrisini girin (3x3 veya 2x2):" << endl;
    for (int i = 0; i < keyMatrix.size(); ++i) {
        vector<int> row;
        for (int j = 0; j < keyMatrix[i].size(); ++j) {
            int value;
            cin >> value;
            row.push_back(value);
        }
        keyMatrix.push_back(row);
    }

    string encryptedText = encryptHillCipher(text, keyMatrix);
    cout << "Şifrelenmiş Metin: " << encryptedText << endl;

    string decryptedText = decryptHillCipher(encryptedText, keyMatrix);
    cout << "Deşifre Edilmiş Metin: " << decryptedText << endl;

    return 0;
}
