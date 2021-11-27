#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<string, string> v;
    int N, M;
    cin >> N >> M;
    while (N--) {
        string b1, b2;
        cin >> b1 >> b2;
        v.insert({b1, b2});
    }

    while (M--) {
        string b1;
        cin >> b1;
        cout << v[b1] << '\n';
    }
}
