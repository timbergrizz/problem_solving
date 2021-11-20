#include <iostream>
#include <string.h>
using namespace std;


int v[100001]{0, };
bool visit[100001] {false, };
bool check[100001] {false, };

int counter{0};

void dfs(int n){
    visit[n] = true;
    int next = v[n];

    if(!visit[next]) dfs(next);
    else if(!check[next]){
        for(int i = next; i != n; i = v[i]) ++counter;
        ++counter;
    }
    check[n] = true;
}

int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;

        counter = 0;

        memset(visit, false, sizeof(visit));
        memset(check, false, sizeof(check));

        for(int i=1; i<=n; ++i) cin >> v[i];
        for(int i=1; i<=n; ++i){
            if(!visit[i]) dfs(i);
        }
        cout << n - counter << endl;
    }
}