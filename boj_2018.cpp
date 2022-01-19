#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans{0};
    int begin{1}, end{1}, total{1};
    while (end <= N) {
        if (total <= N) total += ++end;
        else total -= begin++;

        if (total == N) ans++;
    }

    cout << ans << '\n';
}