#include <bits/stdc++.h>

using namespace std;

int v[1000001]{0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i <= N; ++i) cin >> v[i];

    vector<int> lis;
    lis.push_back(0);
    for(int i=1; i <= N; ++i){
        if(v[i] > lis.back()) lis.push_back(v[i]);
        else{
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
        }
    }

    cout << lis.size() - 1 << "\n";
}

