#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    map<int, int> v;

    for (int i = 0; i < N; ++i) {
        int b; cin >> b;

        if(v.find(b) == v.end()) v[b]=1;
        else v[b] += 1;
    }

    int M;
    cin >> M;

    int b{0};
    map<int,int>::iterator it;

    while (M--) {
        cin >> b;
        it = v.find(b);

        if(it != v.end()) cout << v[b] << " ";
        else cout << 0 << " ";
    }
    cout << '\n';
}