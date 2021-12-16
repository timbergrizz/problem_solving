#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int v[1000001];
bool visit[1000001];

int F, G, U, D;

void bfs(int S) {
    queue<int> n;
    n.push(S);

    while(!n.empty()){
        int buf = n.front();
        n.pop();
        if(buf == G) return;

        int pos[2] {buf + U, buf - D};

        for(int i=0; i<2; ++i){
            if(pos[i] >= 1 && pos[i] <= F){
                if(!visit[pos[i]]){
                    v[pos[i]] = v[buf] + 1, visit[pos[i]] = true;
                    n.push(pos[i]);
                }
            }
        }

    }
}

int main() {
    memset(v, 0, sizeof(v));
    memset(visit, 0, sizeof(visit));

    int S;
    cin >> F >> S >> G >> U >> D;

    visit[S] = true;
    bfs(S);

    if(!visit[G]) cout << "use the stairs\n";
    else cout << v[G] << "\n";
}