#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> m(2, vector<long long>(2, 1));
const long long mod{1000000007};

vector<vector<long long>> produce(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> r(2, vector<long long>(2));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                r[i][j] = (r[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return r;
}

vector<vector<long long>> dnc(long long n) {
    if (n == 1) return m;

    vector<vector<long long>> buf = dnc(n / 2);
    vector<vector<long long>> r = produce(buf, buf);

    if (n % 2) return produce(r, m);
    else return r;
}

int main() {
    m[0][0] = 0;
    long long N;
    cin >> N;
    vector<vector<long long>> v = dnc(N);
    cout << v[0][1] % mod << endl;
}