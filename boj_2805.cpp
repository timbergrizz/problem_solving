//boj_2805
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long N, M;
    cin >> N >> M;

    vector<long long> woodLen;
    long long max = 0;
    long long min = 0;

    for(long i=0; i<N; ++i){
        long long buf;
        cin >> buf;
        woodLen.push_back(buf);
        max = std::max(max, buf);
    }

    long long result{0};

    long long mid = 0;

    while(min < max){
        mid = (max + min) / 2;

        long long totalWoodLen{0};
        for(long long i=0; i < N; ++i){
            if(woodLen[i] > mid) totalWoodLen += (woodLen[i] - mid);
        }

        if(totalWoodLen < M){
            max = mid;
        }
        else {
            result = mid;
            min = mid + 1;
        }
    }
    printf("%lld\n", result);
}