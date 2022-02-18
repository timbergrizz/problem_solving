#include <bits/stdc++.h>

using namespace std;

int v[1024][1024];

int maximum(int x, int y, int N) {
    if (N == 1) return v[x][y];

    int h{N / 2};
    vector<int> val;

    for(int i=0; i < N; i += h){
        for(int j=0; j < N; j += h){
            int buf = maximum(x + i, y + j, N / 2);
            val.push_back(buf);
        }
    }
    sort(val.begin(), val.end());
    return val[2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> v[i][j];
    }

    cout << maximum(0, 0, N) << "\n";
}