#include <bits/stdc++.h>
#define MAX 1e9 + 1;
using namespace std;

typedef vector<int> vi;

int init(int start, int end, int node, vi &tree, vi &a) {
    if (start == end) return tree[node] = a[start];

    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2, tree, a), init(mid + 1, end, node * 2 + 1, tree, a));
}

int minVal(int start, int end, int node, int l, int r, vi &tree) {
    if (end < l || r < start) return MAX;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;

    return min(minVal(start, mid, node * 2, l, r, tree), minVal(mid + 1, end, node * 2 + 1, l, r, tree));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    vector<int> v(N);
    int treeSize = (1 << ((int)ceil(log2(N)) + 1));
    vector<int> tree(treeSize);
    for(int& i : v) cin >> i;
    init(0, N - 1, 1, tree, v);
//    for(int i : tree) cout << i << " ";
//    cout << endl;

    int fir, sec;
    while(M--){
        cin >> fir >> sec;
        cout << minVal(0, N - 1, 1, fir - 1, sec - 1, tree) << "\n";
    }
}