#include <iostream>
#include <vector>
using namespace std;

int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

int chineseRemainderTheorem(const vector<int>& num, const vector<int>& rem) {
    int product = 1;
    int result = 0;

    for (int i = 0; i < num.size(); i++)
        product *= num[i];

    for (int i = 0; i < num.size(); i++) {
        int pp = product / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % product;
}

int main() {
    int n;
    cout << "Kac denklem girilecek: ";
    cin >> n;

    vector<int> num(n), rem(n);

    for (int i = 0; i < n; i++) {
        cout << "Denklem " << i + 1 << " icin mod degerini ve kalan degeri girin: ";
        cin >> num[i] >> rem[i];
    }

    int result = chineseRemainderTheorem(num, rem);

    cout << "Sonuc: " << result << endl;

    return 0;
}