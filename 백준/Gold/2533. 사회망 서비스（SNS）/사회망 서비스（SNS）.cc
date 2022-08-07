#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1010101
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll dp[MAX][2];
vvl v, adj;

//양방향 트리를 단방향 트리로 바꾸는 과정
void tree(ll cur, ll prev) {
    //근데 이거 굳이 안해도 될듯?
    //탐색 과정해서 처리를 해도 될 것 같긴 한데, 모르겠다.
    for (auto n: v[cur]) {
        if (n == prev) continue;

        adj[cur].push_back(n);
        tree(n, cur);
    }
}

// dfs 과정
ll dfs(ll cur, ll type) {
    // 혹시 모르니까 타입은 롱롱으로 통일
    // 매번 dp배열 접근하지말고 레퍼런스 처리하기
    ll &ret = dp[cur][type];
    // 이미 탐색이 완료된 노드에 대해 다시 탐색할 필요 없다.
    // 그냥 기존에 연산했던 결과 바로 반환
    // 이때 타입 2종류에 따라 결과값이 다르므로, 배열단에서 따로 처리된 것을 확인할 수 있다.
    if (ret != -1) return ret;

    // ret = type으로 설정해 처리한다.
    ret = type;
    // leaf 노드이면 더 볼 필요 없고 반환한다.
    if (adj[cur].empty()) return ret;

    // 현재 조사하는 type이 얼리어답터일때랑 일반일 때에 따라 경우가 나뉘게 된다.
    // 일반인 경우 무조건 자식으로 얼리어답터가 와야 하고, 얼리어답터면 뭐가 오던 상관 없다.
    if (!type) {
        for (ll i: adj[cur]) ret += dfs(i, 1);
    } else {
        for (ll i: adj[cur]) ret += min(dfs(i, 1), dfs(i, 0));
    }

    return ret;
}

int main() {
    FASTIO
    ll N, c1, c2;
    cin >> N;
    v = vvl(N + 1), adj = vvl(N + 1);

    FOR(i, N - 1) {
        cin >> c1 >> c2;
        v[c1].push_back(c2);
        v[c2].push_back(c1);
    }

    // 트리로 만들 때, 루트의 기준은 상관 없다.
    // 어차피 방향성이 없는 상태에서 방향성을 부여하는 것이기 때문에, 모양이 달라질 뿐 구성이 달라지지 않는다.
    tree(1, 0);
    memset(dp, -1, sizeof dp);

    cout << min(dfs(1, 0), dfs(1, 1));
}