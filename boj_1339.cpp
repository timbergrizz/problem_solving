#include <bits/stdc++.h>

using namespace std;

map<char, int> m;
vector<string> v;

int stringToNum(const string &n) {
    int result{0};
    for (char c: n) {
        result *= 10;
        result += m[c];
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    string buf;
    while (N--) {
        cin >> buf;
        v.push_back(buf);
        int n{1};
        std::reverse(buf.begin(), buf.end());
        //그리디 알고리즘에서는, 어떠한 것을 기준으로 삼을 것인지 결정하는 것이 중요할 것.
        //이 문제의 경우, 각 알파벳마다 가중치로 자릿수를 더해줘, 배정된 자릿수가 큰 수부터 수가 배정될 수 있도록 한다.
        for (char c: buf) {
            m[c] += n;
            n *= 10;
        }
    }

    priority_queue<pair<int, char>> pq;
    for (auto it: m) pq.push({it.second, it.first});
    int cnt{0};
    while (!pq.empty()) {
        auto t{pq.top()};
        pq.pop();
        m[t.second] = 9 - cnt++;
    }
    // 출력 초과면 출력 초과라고 좀 써달라고 ㅅㅂ
    // for(auto it : m) cout << it.first << " " << it.second << endl;

    int res{0};
    for (string s: v) res += stringToNum(s);
    cout << res << "\n";
}