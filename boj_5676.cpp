#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int update(vi &tree, int start, int end, int node, int idx, int val) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] = val;

    int mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx, val) * update(tree, mid+1, end, node * 2 + 1, idx, val);
}

int mul(vi &tree, int start, int end, int node, int l, int r) {
//    cout << start << end << endl;
    if(r < start || end < l) return 1;
    if(l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return mul(tree, start, mid, node * 2, l, r) * mul(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;

    int treeSize = 1000000;
    vector<int> tree(treeSize);
    while (cin >> N >> K) {
        for(int &i : tree) i = 0;

        int c1, c2;
        for (int i = 0; i < N; ++i) {
            cin >> c1;
            if(c1 < 0) c1 = -1;
            else if(c1 > 0) c1 = 1;
            update(tree, 0, N-1, 1, i, c1);
        }

        char oper;
        while(K--){
            cin >> oper >> c1 >> c2;
            if(oper == 'C'){
                if(c2 < 0) c2 = -1;
                else if(c2 > 0) c2 = 1;
                update(tree, 0, N-1, 1, c1 - 1, c2);
            }
            else {
                int val = mul(tree, 0, N - 1, 1, min(c1, c2) - 1, max(c1, c2) - 1);
//                cout << val << ' ';
                if(val < 0) cout << "-";
                else if(val > 0) cout << "+";
                else cout << 0;
//                cout << endl;
            }
        }
        cout << "\n";
    }
}