#include <iostream>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        map<string, int> v;
        int n;
        cin >> n;
        while (n--) {
            string buf1, buf2; cin >> buf1 >> buf2;
            if(v.find(buf2) == v.end()) v[buf2] = 1;
            else v[buf2] += 1;
        }

        int result{1};
        for(pair<string, int> it : v){
            result *= (it.second  + 1);
        }

        cout << result - 1 << "\n";
    }
}