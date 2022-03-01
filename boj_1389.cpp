#include <bits/stdc++.h>
using namespace std;

bool v[101][101]{false, };
int res[101][101]{0, };
int N;

int floydwarshall(){
    for(int i=1; i <= N; ++i){
        for(int j=1; j <= N; ++j) {
            if(i == j) continue;
            else if(!v[i][j]) res[i][j] = N + 1;
            else res[i][j] = 1;
        }
    }
    for(int k=1; k <= N; ++k){
        for(int i=1; i <= N; ++i) {
            for(int j=1; j <= N; ++j) {
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
            }
        }
    }

    int minIdx{0}, minVal{1000000001};

    for(int i=1; i <= N; ++i){
        int sum{0};
        for(int j=1; j <= N; ++j) {
            sum += res[i][j];
        }
        if(minVal > sum) minIdx = i, minVal = sum;
    }

    return minIdx;
}

int main() {
    int M;
    cin >> N >> M;
    int fir, sec;

    while(M--){
        cin >> fir >> sec;
        v[fir][sec] = v[sec][fir] = true;
    }
    cout << floydwarshall() << '\n';
}