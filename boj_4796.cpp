#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, P, V;
    int caseNum{1};
    while(true){
        cin >> L >> P >> V;
        if(!L && !P && !V) break;

        int result{0};
        while(V){
            if(V < P) result += min(V, L), V = 0;
            else result += L, V -= P;
        }
        cout << "Case " << caseNum++ << ": " << result << "\n";
    }
}