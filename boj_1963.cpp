#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

bool visit[10000];
int target;

bool nextPrime(int n) {
    if ((n & 1) == 0)
        return (n == 2);

    for (int i = 3; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int bfs(int p) {
    queue<pair<int, int>> n;
    n.push({p, 0});

    while (!n.empty()) {
        pair<int, int> val = n.front();
        n.pop();

        if (val.first == target) return val.second;
        int buf{0};

        int num = (val.first / 10) * 10;
        for (int i = 0; i < 10; ++i) {
            buf = num + i;
            if (!visit[buf] && nextPrime(buf)) {
                visit[buf] = true;
                n.push({buf, val.second + 1});
            }
        }

        num = (val.first / 100) * 100 + val.first % 10;
        for (int i = 0; i < 10; ++i) {
            buf = num + i * 10;
            if (!visit[buf] && nextPrime(buf)) {
                visit[buf] = true;
                n.push({buf, val.second + 1});
            }
        }

        num = (val.first / 1000) * 1000 + val.first % 100;
        for (int i = 0; i < 10; ++i) {
            buf = num + i * 100;
            if (!visit[buf] && nextPrime(buf)) {
                visit[buf] = true;
                n.push({buf, val.second + 1});
            }
        }

        num = val.first % 1000;
        for (int i = 1; i < 10; ++i) {
            buf = num + i * 1000;
            if (!visit[buf] && nextPrime(buf)) {
                visit[buf] = true;
                n.push({buf, val.second + 1});
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(visit, false, sizeof(visit));

        int start;
        cin >> start >> target;

        visit[start] = true;
        int res = bfs(start);
        cout << res << endl;
    }
}