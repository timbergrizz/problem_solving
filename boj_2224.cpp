#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

map<char, int> m;
map<int, char> toC;
int v[52][52];

void floyd_warshall() {
    FOR(k, 52) {
        FOR(i, 52) {
            FOR(j, 52) if (v[i][k] && v[k][j]) v[i][j] = true;
        }
    }
}

int main() {
    FOR(i, 26) m['A' + i] = i;
    FOR(i, 26) toC[i] = 'A' + i;
    FOR(i, 26) m['a' + i] = i + 26;
    FOR(i, 26) toC[i + 26] = 'a' + i;

    int N;
    cin >> N;
    cin.clear();
    FOR(i, N) {
        char fir, sec;
        string buf;

        cin >> fir >> buf >> sec;
        v[m[fir]][m[sec]] = 1;
    }

    floyd_warshall();
    queue<string> q;
    FOR(i, 52) {
        FOR(j, 52) {
            if(i == j) continue;
            if (v[i][j]) {
                string buf;
                buf.push_back(toC[i]);
                buf += " => ";
                buf.push_back(toC[j]);

                q.push(buf);
            }
        }
    }
    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.front() << "\n";
        q.pop();
    }
}