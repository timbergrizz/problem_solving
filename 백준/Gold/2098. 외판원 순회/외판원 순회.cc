#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

const int inf = 1e9;

int N;
int cost[16][16], dp[16][1 << 16];

// route에는 방문한 도시의 정보가 저장된다.
// integer 변수를 통해 데이터를 저장함.
int get_result(int cur, int route) {
    //route의 마지막 경우로, 더이상 다른 노드를 방문할 필요가 없을 때
    if (route == (1 << N) - 1) {
        // cur 0 == 0 이면 그 도시로 향하는 길이 없는 경우가 된다.
        // 이때는 무한을 반환해서 그 경로를 날리면 된다.
        if (cost[cur][0] == 0) return inf;
        return cost[cur][0];
    }

    // 현재 경로에서 이동하는데 드는 비용을 저장한다.
    // 이때, 이미 방문한 노드들에 대한 정보는 route에 담기게 된다.

    int &ret = dp[cur][route];
    if (ret != -1) return ret;

    ret = inf;
    //모든 노드에 대해 방문하면서,
    FOR(next, N) {
        // 0번 노드부터 N - 1번째 노드까지 확인
        // 방문할 수 없는 노드들에 대해서는 생략한다.
        if (!cost[cur][next]) continue;
        // 이미 경로에 포함된 방문한 노드, 그러니까 route에서 비트가 1로 바뀐 노드에 대해서도 다시 방문하지 않는다.  
        if ((route & (1 << next)) == (1 << next)) continue;
        
        //위의 두 경우를 제외하고는, route에 경로를 포함하여 방문을 진행한다.
        ret = min(ret, cost[cur][next] + get_result(next, route | 1 << next));
    }
    //결과값을 반환하자.
    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> N;

    FOR(i, N) {
        FOR(j, N) cin >> cost[i][j];
    }

    cout << get_result(0, 1);
}