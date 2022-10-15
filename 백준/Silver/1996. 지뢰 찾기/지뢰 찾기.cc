#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

int v[1010][1010]{0, };

int main() {
    int N; cin >> N;
    string c1;

    FOR(i, N){
        cin >> c1;
        FOR(j, N) {
            if (c1[j] == '.') continue;

            v[i][j] = -1;
            FOR(k, 3) {
                int y = i + k - 1;
                if (y < 0 || y >= N) continue;

                FOR(l, 3) {
                    int x = j + l - 1;

                    if (x < 0 || x >= N) continue;
                    if (v[y][x] == -1) continue;
                    if (x == j && y == i) continue;

                    v[y][x] += (int)(c1[j] - '0');
                }

            }
        }
    }

    FOR(i, N){
        FOR(j, N){
            if(v[i][j] == -1) cout << "*";
            else if(v[i][j] >= 10) cout << "M";
            else cout << v[i][j];
        }
        cout << "\n";
    }
}