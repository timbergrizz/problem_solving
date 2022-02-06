#include <bits/stdc++.h>

#define loop(start, end, i) for(int i=start; i < end; ++i)
using namespace std;

int main() {
    multiset<int> s;
    int N;
    cin >> N;
    int buf;
    long long answer{0};

    loop(0, N, i) {
        cin >> buf;
        s.insert(buf);
    }

    while (!s.empty()) {
        if (s.size() < 3) {
            while (!s.empty()) {
                answer += *s.begin();
                s.erase(s.begin());
            }
            break;
        }

        answer += *s.rbegin();
        s.erase(std::prev(s.end()));
        answer += *s.rbegin();
        s.erase(std::prev(s.end()));
        s.erase(std::prev(s.end()));
    }
    cout << answer << "\n";
}