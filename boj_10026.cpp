#include <iostream>
#include <utility>
#include <queue>

using namespace std;

char mX[4] = {1, -1, 0, 0};
char mY[4] = {0, 0, 1, -1};

char v[100][100];
char v2[100][100];

int N;

void bfs(pair<int, int> inp, char c) {
    queue<pair<int, int>> n;
    n.push(inp);

    while (!n.empty()) {
        pair<int, int> cur = n.front();
        n.pop();

        for (int i = 0; i < 4; ++i) {
            int bufX = cur.first + mX[i], bufY = cur.second + mY[i];
            if (bufX >= 0 && bufX < N && bufY >= 0 && bufY < N) {
                if (v[bufX][bufY] == c) {
                    v[bufX][bufY] = 'A';
                    n.push({bufX, bufY});
                }
            }
        }
    }
}

void bfs_2(pair<int, int> inp, char c) {
    queue<pair<int, int>> n;
    n.push(inp);

    while (!n.empty()) {
        pair<int, int> cur = n.front();
        n.pop();

        for (int i = 0; i < 4; ++i) {
            int bufX = cur.first + mX[i], bufY = cur.second + mY[i];
            if (bufX >= 0 && bufX < N && bufY >= 0 && bufY < N) {
                if (v2[bufX][bufY] == c) {
                    v2[bufX][bufY] = 'A';
                    n.push({bufX, bufY});
                }
            }
        }
    }
}


int main() {
    cin >> N;

    string buf;
    for (int i = 0; i < N; ++i) {
        cin >> buf;
        for (int j = 0; j < N; ++j) {
            v[i][j] = v2[i][j] = buf[j];
            if(buf[j] == 'G') v2[i][j] = 'R';
        }
    }

    int counter[2]{0, 0};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[i][j] != 'A'){
                bfs({i, j}, v[i][j]);
                ++counter[0];
            }
            if(v2[i][j] != 'A'){
                bfs_2({i, j}, v2[i][j]);
                ++counter[1];
            }
        }
    }
    cout << counter[0] << " " << counter[1] << "\n";
}