#include <bits/stdc++.h>

#define FOR(i, j, N) for(int i=j; i<N; ++i)
using namespace std;

typedef vector<int> vi;

void failure_function(string &P, vi &F, int M) {
    int cmp{0};

    FOR(i, 1, M) {
        while (cmp > 0 && P[i] != P[cmp]) cmp = F[cmp - 1];
        if (P[i] == P[cmp]) F[i] = ++cmp;
    }
}

void KMP(string &T, string &P, vi &result, int N, int M) {
    vi F(P.size());
    failure_function(P, F, M);

    int cmp = 0;
    FOR(i, 0, N) {
        while (cmp > 0 && T[i] != P[cmp]) cmp = F[cmp - 1];
        if (T[i] == P[cmp]) {
            if (cmp == M - 1){
                result.push_back(i - cmp + 1);
                cmp = F[cmp];
            }
            else ++cmp;
        }
    }
}


int main() {
    string T, P;
    getline(cin, T);
    getline(cin, P);

    int n = T.size(), m = P.size();

    int i = 0;
    vi result;

    KMP(T, P, result, n, m);

    cout << result.size() << "\n";
    for (int &i: result) cout << i << " ";
}