#include <iostream>
#include <algorithm>
using namespace std;

long long v[100001];
int N;

int abs(int m){
    if(m < 0) return (-1) * m;
    return m;
}

int main(){
    cin >> N;
    for(int i=0; i < N; ++i) cin >> v[i];
    sort(v, v + N);

    long long l = 0, r = N - 1;
    long long dif = 200000000000, minL{0}, minR{0};
    while(l < r){
        long long sum = v[l] + v[r];

        if(dif > abs(sum))
        {
            dif = abs(sum), minL = l, minR = r;
            if(sum == 0) break;
        }

        if(sum < 0) l++;
        else r--;
    }
    cout << v[minL] << " " << v[minR] << "\n";
}