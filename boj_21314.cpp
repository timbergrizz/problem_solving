#include <bits/stdc++.h>

using namespace std;

int main() {
    string v;
    cin >> v;

    int counter{0};
    string answer;

    for (char c: v) {
        if (c == 'M') counter++;
        if (c == 'K') {
            string buf = "5";
            while (counter--) buf += '0';
            answer += buf, counter = 0;
        }
    }
    while (counter--) answer += '1';
    cout << answer << "\n";

    answer = "", counter = 0;

    for (char c: v) {
        if (c == 'M') counter++;
        if (c == 'K') {
            if (counter) {
                string buf;
                buf += '1';
                while (--counter) buf += '0';
                answer += buf, counter = 0;
            }
            answer += '5';
        }
    }

    if (counter) {
        answer += '1';
        while (--counter) answer += '0';
    }

    cout << answer << "\n";
}