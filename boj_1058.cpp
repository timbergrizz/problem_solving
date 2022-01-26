#include <iostream>
#include <memory.h>
#include <utility>
#include <queue>
using namespace std;

bool v[51][51];
int visit[51];
int n;

int bfs(int p){
    queue<int> q;
    q.push(p);

    while(!q.empty()){
        int f = q.front();
//        cout << f << " " << visit[f] << endl;
        q.pop();

        for(int i=1; i <= n; ++i){
            if(!v[f][i] || visit[i] != 0) continue;
            visit[i] = visit[f] + 1;
            q.push(i);
        }
    }

    int ret{0};
    for(int i=1; i <= n; ++i){
        if(visit[i] > 1 && visit[i] <= 3) ++ret;
    }
    return ret;
}

int main(){
    cin >> n;
    char buf;
    for(int i=1; i <= n; ++i){
        for(int j=1; j <= n; ++j){
            cin >> buf;
            (buf == 'N' ? v[i][j] = false : v[i][j] = true);
        }
    }

    int result{0};
    int d;
    for(int i=1; i <= n ; ++i){
        memset(visit, 0, sizeof visit);
        visit[i] = 1;
//        cout << bfs(i) << endl;
        result = max(result, bfs(i));
//        cout << i << " " << result << endl;
    }
    cout << result << '\n';
}