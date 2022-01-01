#include <iostream>
using namespace std;

int p[5] = {1, 2, 3, 5, 7};
int N;

int check(int n) {
    if(n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (!(n % i)) return false;
    }
    return true;
}

void dfs(int n, int size) {
    if (!check(n)) return;
    if (size == N) {
        cout << n << "\n";
        return;
    }
    for (int i = 1; i < 10; ++i) {
        dfs(n * 10 + i, size + 1);
    }
}

int main() {
    cin >> N;
    dfs(0, 0);
}