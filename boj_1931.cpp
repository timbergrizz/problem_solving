#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string buf;
    cin >> buf;
    int len = buf.size();

    vector<int> v(len);
    int val{0};
    bool zeroExist{false};

    for (int i = 0; i < len; ++i) {
        v[i] = buf[i] - '0';
        if(v[i] == 0 && !zeroExist) zeroExist = true;
        val += v[i];
    }

    if (!zeroExist || val % 3 != 0) {
        cout << -1 << endl;
    }
    else{
        sort(v.begin(), v.end());
        for(int i=len - 1; i>=0; --i) cout << v[i];
        cout << endl;
    }
}