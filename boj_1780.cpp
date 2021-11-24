#include <iostream>

using namespace std;

int v[2188][2188];
int papers[3]{0, 0, 0};

int p(int x, int y, int n) {
    if (n == 1) return v[x][y];
    int re[4]{0, 0, 0, 0};

    int bufN{n / 3};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int buf = p(x + i * bufN, y + j * bufN, bufN);
            ++re[buf + 2];
        }
    }

    for(int i=1; i<=3; ++i) {
        //        cout << re[i] << " ";
        if(re[i] == 9) return i - 2;
        papers[i-1] += re[i];
    }
    return -2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> v[i][j];
    }

    int buf = p(0, 0, N);
    if(buf != -2) ++papers[buf+1];

    for (int i = 0; i < 3; ++i) {
        cout << papers[i] << '\n';
    }
}