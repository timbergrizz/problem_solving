#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
int v[101];
int ls[101];

void bfs(int p) {
    queue<int> q;
    q.push(p);

    while (!q.empty()) {
        int val = q.front();
        q.pop();

        int pos{0};
        for(int i=1; i<=6; ++i){
            if(val + i < 101){
                pos = ls[val + i];
//                cout << pos << " ";
                if(!v[pos]){
                    v[pos] = v[val] + 1;
                    q.push(pos);
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    int x, y;
    memset(v, 0, sizeof(v));
    memset(ls, 0, sizeof(ls));

    while (N--) {
        cin >> x >> y;
        ls[x] = y;
    }
    while (M--) {
        cin >> x >> y;
        ls[x] = y;
    }
    for (int i = 0; i < 101; ++i) {
        if (!ls[i]) ls[i] = i;
    }

    bfs(1);
//    cout << endl;
    cout << v[100] << endl;
}