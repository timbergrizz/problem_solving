#include <iostream>
#include <memory.h>

using namespace std;

bool v[3073][6145]{false};
long long N;

void paint(int x, int y, int N) {
    if (N == 3) {
        v[x][y] = v[x + 1][y - 1] = v[x + 1][y + 1] = true;
        for (int i = y - 2; i <= y + 2; ++i) v[x + 2][i] = true;
        return;
    }

    int bufN = N / 2;

    paint(x, y, bufN);
    paint(x + bufN, y - bufN, bufN);
    paint(x + bufN, y + bufN, bufN);
}

int main() {
    cin >> N;
    memset(v, false, 3073 * 6145);
    paint(0, N-1, N);
    for (int i = 0; i <= N; ++i) {
        for (int j{0}; j <= N * 2; ++j)
            if (v[i][j]) cout << '*';
            else cout << ' ';
            cout << endl;
    }
}