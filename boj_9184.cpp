#include <bits/stdc++.h>

#define MOD 1000000007LL
using namespace std;

typedef long long ll;
int v[21][21][21]{1,};

int main() {
    for (int i = 0; i <= 20; ++i) {
        for (int j = 0; j <= 20; ++j) {
            for (int k = 0; k <= 20; ++k) {
                if (!i || !j || !k) v[i][j][k] = 1;
                else if (i < j && j < k) v[i][j][k] = v[i][j][k - 1] + v[i][j - 1][k - 1] - v[i][j - 1][k];
                else v[i][j][k] = v[i - 1][j][k] + v[i - 1][j - 1][k] + v[i - 1][j][k - 1] - v[i - 1][j - 1][k - 1];
            }
        }
    }

    int a, b, c;
    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;

        int result{0};
        if (a <= 0 || b <= 0 || c <= 0) result = 1;
        else if (a > 20 || b > 20 || c > 20) result = v[20][20][20];
        else result = v[a][b][c];

        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
    }
}