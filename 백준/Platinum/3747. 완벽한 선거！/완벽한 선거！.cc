#include <bits/stdc++.h>
#define SET(i) (i < 0 ? N - i : i)
#define NEG(i) (i > N ? i - N : i + N)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;

vvi v;
vi id, scc;
int N, cur_id{0}, idx{0};

int dfs(int cur, si &s){
    id[cur] = ++cur_id;
    s.push(cur);
    int link = id[cur];

    for(auto it : v[cur]){
        if(!id[it]) link = min(link, dfs(it, s));
        if(scc[it] == -1) link = min(link, id[it]);
    }

    if(id[cur] == link){
        while(true){
            int t = s.top();
            s.pop();

            scc[t] = idx;
            if(t == cur) break;
        }
        ++idx;
    }

    return link;
}

bool check(){
    for(int i = 1; i <= N; ++i){
        if(scc[i] == scc[i + N]) return false;
    }
    return true;
}

void init(){
    v.clear(); v.resize( 2 * N + 10);
    id.clear(); id.resize(2 * N + 10);
    scc.clear(); scc.resize(2 * N + 10, -1);
}

int main() {
    FASTIO
    int M, c1, c2;
    while(cin >> N >> M){
        init();
        while (M--){
            cin >> c1 >> c2;
            c1 = SET(c1), c2 = SET(c2);

            v[NEG(c1)].push_back(c2);
            v[NEG(c2)].push_back(c1);
        }
        si s;
        for(int i=1; i <= 2 * N + 1; ++i){
            if(!id[i]) dfs(i, s);
        }

//        for(int i : scc) cout << i << " ";
//        cout << endl;

        cout << check() << "\n";
    }
}