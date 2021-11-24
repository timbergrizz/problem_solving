#include <iostream>

using namespace std;

bool v[6561][6561]{false,};

void set(int x, int y, int n) {
    if (n == 1) v[x][y] = true;
    else {
        int bufN = n / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == 1 && j == 1) continue;
                set(x + i * bufN, y + j * bufN, bufN);
            }
        }
    }
}

int main() {
    int N; cin >> N;
    set(0, 0, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[i][j]) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

