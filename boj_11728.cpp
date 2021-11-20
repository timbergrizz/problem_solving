#include <iostream>

using namespace std;

int N, M;
long long v1[1000001], v2[1000001], v3[2000001];

void append() {
    int v1_i{0}, v2_i{0};
    while (v1_i < N && v2_i < M) {
        if (v1[v1_i] < v2[v2_i]) {
            v3[v1_i + v2_i] = v1[v1_i];
            v1_i++;
        } else {
            v3[v1_i + v2_i] = v2[v2_i];
            v2_i++;
        }
    }

    if (v1_i < N) {
        for (; v1_i < N; ++v1_i) v3[v1_i + v2_i] = v1[v1_i];
    } else
        for (; v2_i < M; ++v2_i) v3[v1_i + v2_i] = v2[v2_i];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> v1[i];
    for (int i = 0; i < M; ++i) cin >> v2[i];

    append();
    for(int i=0; i< N + M; ++i) cout << v3[i] << " ";
    cout << '\n';
}