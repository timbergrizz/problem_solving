#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> v(N+1);

    for(int i=1; i<=N; ++i) v[i] = i;
    for(int i=4; i<=N; ++i){
        for(int j=2; j*j <= i; ++j)
            v[i] = min(v[i], v[i - j * j] + 1);
    }
    cout << v[N] << "\n";
};