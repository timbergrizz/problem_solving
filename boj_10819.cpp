#include <iostream>
using namespace std;

int N, result{0};
int A[8], n[8];
bool visit[8];

int abs(int a){
    if(a < 0) return a * (-1);
    return a;
}

int check(){
    int ret{0};
    for(int i=1; i < N; ++i) ret += abs(n[i] - n[i-1]);
    return ret;
}

void bf(int size){
    if(size == N) {
        result = max(check(), result);
        return;
    }

    for(int i=0; i < N; ++i ){
        if(visit[i]) continue;
        visit[i] = true, n[size] = A[i];
        bf(size + 1);
        visit[i] = false;
    }
}

int main(){
    cin >> N;
    for(int i=0; i < N; ++i) cin >> A[i];
    bf(0);
    cout << result << "\n";
}