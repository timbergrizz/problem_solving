#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for(int &i : v) cin >> i;

    auto l{v.begin()}, r{v.end() - 1};
    int result{200000000}, sum;

    while(l < r){
        sum = *l + *r;
//        cout << sum << endl;
        if(abs(sum) < abs(result)) result = sum;

        if(sum < 0) l++;
        else r--;
    }
    cout << result << "\n";
}