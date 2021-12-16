#include <iostream>
#include <utility>

using namespace std;

long long gcd(long long a, long long b) {
    if (a < b) swap(a, b);

    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long long frac[2][2];
    long long result[2]{0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) cin >> frac[i][j];
    }

    long long g = gcd(frac[0][1], frac[1][1]);
    result[1] = (frac[0][1] / g)  * (frac[1][1] / g) * g;
    result[0] = frac[0][0] * (result[1] / frac[0][1]) + frac[1][0] * (result[1] / frac[1][1]);

    g = gcd(result[0], result[1]);
    result[0] /= g, result[1] /= g;

    cout << result[0] << " " << result[1] << "\n";
}