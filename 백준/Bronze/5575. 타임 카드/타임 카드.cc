#include <bits/stdc++.h>
using namespace std;

struct Time{ int h{0}, m{0}, s{0}; };

Time seconds(Time a, Time b){
    int total_seconds = {(b.h - a.h ) * 3600 + (b.m - a.m) * 60 + (b.s - a.s)};
    return Time{total_seconds/3600, (total_seconds%3600) / 60, total_seconds % 60};
}

int main(){
    int cnt{3};
    while(cnt--){
        Time a, b;
        cin >> a.h >> a.m >> a.s;
        cin >> b.h >> b.m >> b.s;
        Time c = seconds(a, b);
        cout << c.h << " " << c.m << " " << c.s << "\n";
    }
}