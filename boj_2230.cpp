#include <iostream>
#include <algorithm>
using namespace std;

int v[100001];

int main(){
    long long N, M, minlen{2000000001};
    cin >> N >> M;
    for(int i=0; i<N; ++i) cin >> v[i];
    sort(v, v + N);
    int l{0}, r{0};

    while(r <= N){
        if(v[r] - v[l] < M) ++r;
        else{
            if(v[r] - v[l] < minlen) minlen = v[r] - v[l];
            ++l;
        }
    }
    cout << minlen << endl;
}
