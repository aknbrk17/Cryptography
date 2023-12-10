#include <iostream>

using namespace std;

void gcdExt(int n, int m, int &g, int &t, int &s) {
    if (m == 0) {
        g = n;
        t = 1;
        s = 0;
        return;
    }

    int gTemp, tTemp, sTemp;
    gcdExt(m, n % m, gTemp, tTemp, sTemp);

    g = gTemp;
    t = sTemp;
    s = tTemp - (n / m) * sTemp;
}

int main() {
    int n, m, g, t, s;

    cout << "Enter two numbers: ";
    cin >> n >> m;

    gcdExt(n, m, g, t, s);

    cout << "gcd(" << n << ", " << m << ") = " << g << endl;
    cout << "gcd(" << n << ", " << m << ") = "  << n << " * " << t << " + " << m << " * " << s << " = " << g << endl;

    return 0;
}