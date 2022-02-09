#include <bits/stdc++.h>

using namespace std;

int M, K;

// 이런건 숫자 입력이어도 스트링으로 처리 해도 문제 없다.
// 숫자 쓰려고 개고생하지 말고 문자열로 처리하자. 어차피 대소비교 똑같이 된다.

string bfs(string N) {
    queue<string> q;
    q.push(N);

    for (int cnt = 1; cnt <= K; ++cnt) {
        int currentSize = (int) q.size();
        map<string, bool> m;

        for (int i = 0; i < currentSize; ++i) {
            string f = q.front(); q.pop();

            if(m[f]) continue;
            m[f] = true;

            for (int j = 0; j < M; ++j) {
                for (int k = j + 1; k < M; ++k) {
                    if (j == 0 && f[k] == '0') continue;
                    std::swap(f[j], f[k]);
                    q.push(f);
                    std::swap(f[j], f[k]);
                }
            }
        }
    }
    string answer = "0";
    while(!q.empty()){
        answer = max(answer, q.front());
        q.pop();
    }

    if(answer[0] == '0') answer = "-1";
    return answer;
}

int main() {
    string N;
    cin >> N >> K;
    M = (int) N.size();

    cout << bfs(N) << "\n";
}