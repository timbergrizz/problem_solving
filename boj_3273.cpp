#include <bits/stdc++.h>

#define INF 100000000
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);

    for(int i=0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    int x;
    cin >> x;

    auto l = v.begin();
    auto r = v.end() - 1;

    int cnt{0};
    while(l < r){
        int sum = *l + *r;
        if(sum < x){
            l++;
        }
        else{
            if(sum == x) cnt++;
            r--;
        }
    }
    cout << cnt << endl;
}