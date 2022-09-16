#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=1; i <= END; ++i)
using namespace std;

int arr[28]{};

bool check_string(string &buf) {
    arr[buf[0] - 'a']++;
    FOR(i, buf.size() - 1) {
        if (buf[i] != buf[i - 1] && arr[buf[i] - 'a']) return false;
        arr[buf[i] - 'a']++;
    }
    return true;
};

int main() {
    FASTIO
    int N, result{0};
    cin >> N;
    string buf;

    while (N--) {
        cin >> buf;
        memset(arr, 0, sizeof arr);
        if(check_string(buf)) result++;
    }

    cout << result;
}