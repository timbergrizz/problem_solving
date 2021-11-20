#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<int> v(N);

    for(int i=0; i<N; ++i){
        int buf; cin >> buf;
        v[i] = buf;
    }
    sort(v.begin(), v.end());

    int M; cin >> M;
    for(int i=0; i<M; ++i){
        int buf; cin >> buf;
        if(binary_search(v.begin(), v.end(), buf)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
