#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K; cin >> N >> K;
    vector<int> v(N);

    for(int &i : v) cin >> i;

    int startPoint{0}, endPoint{K - 1}, sum{0};
    for(int i=0; i < K; ++i) sum += v[i];
    int result = sum;

    while(startPoint < N){
        sum += v[++endPoint % N];

        sum -= v[startPoint];
        startPoint += 1;

        result = max(sum, result);
    }
    cout << result << endl;
}