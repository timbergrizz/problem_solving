#include <iostream>
#include <vector>
using namespace std;

int N;

vector<vector<int>> v;

vector<vector<int>> produce(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> r(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                r[i][j] = (r[i][j] + (a[i][k] * b[k][j]) % 1000) % 1000;
            }
        }
    }
    return r;
}

vector<vector<int>> dnc(long long n) {
    if(n == 1) return v;

    vector<vector<int>> buf = dnc(n / 2);
    vector<vector<int>> p = produce(buf, buf);
    if(n % 2) return produce(p, v);
    else return p;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);
    long long b; cin >> N >> b;

    for(int i=0; i<N; ++i){
        v.push_back(vector<int>(N));
        for(int j=0; j<N; ++j)  cin >> v[i][j];
    }

    vector<vector<int>> r = dnc(b);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cout << r[i][j] % 1000 << " ";
        cout << "\n";
    }
}