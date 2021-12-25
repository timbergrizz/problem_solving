#include <iostream>
#include <memory.h>
using namespace std;

int v[15][15];
int ans{0};
int N;

void set(int x, int y){
    ++v[x][y];
    for(int k=0; k<N; ++k){
        ++v[x][k], ++v[k][y];
        if(x - k >= 0){
            if(y - k >= 0) ++v[x-k][y-k];
            if(y + k < N) ++v[x-k][y+k];
        }
        if(x + k < N){
            if(y - k >= 0) ++v[x+k][y-k];
            if(y + k < N) ++v[x+k][y+k];
        }
    }
}

void clear(int x, int y){
    --v[x][y];
    for(int k=0; k<N; ++k){
        --v[x][k], --v[k][y];
        if(x - k >= 0){
            if(y - k >= 0) --v[x-k][y-k];
            if(y + k < N) --v[x-k][y+k];
        }
        if(x + k < N){
            if(y - k >= 0) --v[x+k][y-k];
            if(y + k < N) --v[x+k][y+k];
        }
    }
}

void dfs(int j){
    if(j == N) {
        ans += 1;
        return;
    }

    for(int i=0; i<N; ++i){
        if(!v[i][j]){
            set(i, j);
            dfs(j + 1);
            clear(i, j);
        }
    }
}

int main(){
    memset(v, 0, sizeof (v));
    cin >> N;
    dfs(0);
    cout << ans << endl;
}