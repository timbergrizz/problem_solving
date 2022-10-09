#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef long long ll;

int v[1010][5]{0,};
int main() {
    int N, M;
    string c1;
    cin >> N >> M;

    FOR(i, N) {
        cin >> c1;
        FOR(j, M){
            if(c1[j - 1] == 'A') ++v[j][1];
            else if(c1[j - 1] == 'C') ++v[j][2];
            else if(c1[j - 1] == 'G') ++v[j][3];
            else if(c1[j - 1] == 'T') ++v[j][4];
        }
    }

    string dna = "AACGT", result;
    int distance{0};
    FOR(i, M){
        int maxIdx{0}, maxVal{0};
        FOR(j, 4){
            if(maxVal < v[i][j]) {
                distance += maxVal;
                maxIdx = j, maxVal = v[i][j];
            }
            else distance += v[i][j];
        }
        result += dna[maxIdx];
    }
    cout << result << "\n" << distance;
}