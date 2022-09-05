#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=0; i < END; ++i)
using namespace std;


int v[27]{0,};

int main() {
    FASTIO
    string str;
    cin >> str;
    for (auto it: str) v[it - 'A']++;

    int odd = -1, flag = 1;

    string answer, answer_rev;

    FOR(i, 26) {
        if (v[i] % 2) {
            if (odd != -1) {
                answer = "I'm Sorry Hansoo";
                break;
            } else odd = i;
        }
    }

    if (answer.empty()) {
        FOR(i, 26) {
            while (v[i] / 2) answer += (char) ('A' + i), v[i] -= 2;
        }
        answer_rev = answer;
        reverse(answer_rev.begin(), answer_rev.end());

        if(odd != -1) answer += (char)('A' + odd);
        answer += answer_rev;
    }

    cout << answer << endl;
}