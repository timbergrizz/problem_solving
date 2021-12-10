#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

bool visit[10001];

int result;

char func[4]{'D', 'S', 'L', 'R'};

string bfs(int start) {
    queue<pair<int, string>> n;
    n.push({start, ""});

    pair<int, string> p;
    int pos[4];

    while (!n.empty()) {
        p = n.front();
        int val = p.first;

        if (val == result) {
            return p.second;
        }
        n.pop();

        pos[0] = (val * 2) % 10000;
        pos[1] = val == 0 ? 9999 : val - 1;
        pos[2] = (val % 1000) * 10 + val / 1000;
        pos[3] = (val / 10) + (val % 10) * 1000;

        for (int i = 0; i < 4; ++i) {
            if (!visit[pos[i]]) {
                visit[pos[i]] = true;
                n.push({pos[i], p.second + func[i]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        memset(visit, 0, 10001);

        int start;
        cin >> start >> result;

        cout << bfs(start) << '\n';
    }
}