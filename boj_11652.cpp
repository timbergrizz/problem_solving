#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    map<long long, int> m;

    long long j; cin >> j;
    m[j]++;
    long long maxIdx = j;

    for(int i=1; i<N; ++i){
        long long v; cin >> v;
        m[v]++;

        if(m[v] > m[maxIdx]) maxIdx = v;
        else if(m[v] == m[maxIdx] && v < maxIdx) maxIdx = v;
    }

    cout << maxIdx;
}