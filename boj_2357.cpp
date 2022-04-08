#include <bits/stdc++.h>
#define INF 1e9 + 1
using namespace std;

typedef vector<int> vi;
int minInit(vi &v, vi &minTree, int node, int start, int end){
    if(start == end) return minTree[node] = v[start];

    int mid = (start + end) / 2;
    return minTree[node] = min(minInit(v, minTree, node * 2, start, mid), minInit(v, minTree, node * 2 + 1, mid + 1, end));
}

int maxInit(vi &v, vi &maxTree, int node, int start, int end){
    if(start == end) return maxTree[node] = v[start];

    int mid = (start + end) / 2;
    return maxTree[node] = max(maxInit(v, maxTree, node * 2, start, mid), maxInit(v, maxTree, node * 2 + 1, mid + 1, end));
}

int treeMin(vi &minTree, int node, int start, int end, int l, int r){
    if(r < start || end < l) return INF;
    if(l <= start && end <= r) return minTree[node];
//    cout << start << end  << l << r << endl;

    int mid = (start + end) / 2;
    return min(treeMin(minTree, node * 2, start, mid, l, r), treeMin(minTree, node * 2 + 1, mid + 1, end, l, r));
}

int treeMax(vi &maxTree, int node, int start, int end, int l, int r){
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) return maxTree[node];

    int mid = (start + end) / 2;
    return max(treeMax(maxTree, node * 2, start, mid, l, r), treeMax(maxTree, node * 2 + 1, mid + 1, end, l, r));
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    int treeSize = (1 << ((int)ceil(log2(N)) + 1));
    vi v(N);
    vi minTree(treeSize), maxTree(treeSize);

    for(int &i : v) cin >> i;
    minInit(v, minTree, 1, 0, N - 1);
//    for(int i : minTree) cout << i << " ";
//    cout << endl;
    maxInit(v, maxTree, 1, 0, N - 1);
//    for(int i : maxTree) cout << i << " ";
//    cout << endl;

    int fir, sec;
    while(M--){
        cin >> fir >> sec;
        cout << treeMin(minTree, 1, 0, N - 1, fir - 1, sec - 1) << " " << treeMax(maxTree, 1, 0, N - 1, fir - 1, sec - 1) << "\n";
    }
}