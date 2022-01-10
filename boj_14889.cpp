#include <iostream>
#include <memory.h>
using namespace std;

int N, result{1000000};
int v[21][21], visitArr[10], nv[10];
bool visit[21];

int abs(int a){
    if(a < 0) return -1 * a;
    else return a;
}

void dfs(int idx, int n) {
    if (n == N / 2) {
        int A{0}, B{0};

        for (int i = 0; i < n; ++i) {
//            cout << visitArr[i] << " ";
            for (int j = 0; j < n; ++j){
//                cout << visitArr[i] << " " << visitArr[j] << " " << v[visitArr[i]][visitArr[j]] << "\n";
                A += v[visitArr[i]][visitArr[j]];
            }
        }
//        cout << " // ";

        int k{0};
        for(int i=1; i <= N; ++i)
            if(!visit[i]) nv[k++] = i;

        for (int i = 0; i < n; ++i) {
//            cout << nv[i] << " ";
            for (int j = 0; j < n; ++j) B += v[nv[i]][nv[j]];
        }
//        cout << " /// " << A << "  / " << B << "\n";

        if(abs(A - B) < result)  result = abs(A - B);
    }

    for(int i=idx + 1; i <= N; ++i){
        visitArr[n] = i, visit[i] = true;
        dfs(i, n + 1);
        visit[i] = false;
    }
}

int main(){
    memset(v, 0, sizeof(v));
    cin >> N;

    for(int i=1; i<=N; ++i){
        for(int j = 1; j <= N; ++j) cin >> v[i][j];
    }
    dfs(0, 0);
    cout << result << endl;
}