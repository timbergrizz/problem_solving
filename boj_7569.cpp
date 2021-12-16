#include <iostream>
#include <queue>

using namespace std;

int N, M, H;
int v[101][101][101];

int pX[6]{1, -1, 0, 0, 0, 0};
int pY[6]{0, 0, 1, -1, 0, 0};
int pZ[6]{0, 0, 0, 0, 1, -1};
int counter{0};

class pos {
public:
    int x, y, b;

    pos(int _x, int _y, int _b) {
        x = _x, y = _y, b = _b;
    }
};

void bfs(queue<pos> p) {
    while (!p.empty()) {
        pos val = p.front();
        p.pop();

        for (int i = 0; i < 6; ++i) {
            pos buf{val.x + pX[i], val.y + pY[i], val.b + pZ[i]};
            if (buf.x >= 0 && buf.x < M && buf.y >= 0 && buf.y < N && buf.b >= 0 && buf.b < H) {
                if (v[buf.b][buf.y][buf.x] == 0) {
                    p.push(buf);
                    v[buf.b][buf.y][buf.x] = v[val.b][val.y][val.x] + 1;
                }
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;
    queue<pos> p;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                cin >> v[i][j][k];
                if (v[i][j][k] == 1) p.push({k, j, i});
            }
        }
    }

    bfs(p);

    bool flag{false};
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (v[i][j][k] == 0) {
                    flag = true;
                    break;
                }
                if(v[i][j][k] - 1 > counter) counter = v[i][j][k] - 1;
            }
            if (flag) break;
        }
        if (flag) break;
    }
    (flag ? cout << -1 << "\n" : cout << counter << "\n");
}
