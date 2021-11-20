#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--){
        int k; cin >> k;
        multiset<int> N;

        while(k--){
            char c; int v;
            cin >> c >> v;

            if(c == 'I') N.insert(v);
            else if(c == 'D'){
                if(!N.empty()){
                    if (v == -1) N.erase(N.begin());
                    else if(v == 1) N.erase(--N.end());
                }
            }
        }
        if(N.empty()) cout << "EMPTY" << '\n';
        else cout << *(--N.end()) << ' ' << *N.begin() << '\n';
    }
}