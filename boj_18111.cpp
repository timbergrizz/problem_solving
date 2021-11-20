#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Field{
public:
    vector<vector<int>> v;
    int N;
    int M;
    int B;

    Field(int _N, int _M, int _B){
        N = _N, M = _M, B = _B;
        for(int i=0; i<N; ++i){
            v.push_back(vector<int>(M));
        }
    }

    pair<int, int> timeMin(int min){
        int minTime{64000001}, answer{0};

        for(int i=min; i <= 256; ++i){
            int block{B}, time{0};
            for(int j=0; j<N; ++j){
                for(int k=0; k < M; ++k){
                    int buf = v[j][k] - i;
                    block += buf;

                    if(buf < 0) time += buf * (-1);
                    else if(buf > 0) time += buf * 2;
                }
            }
            //            cout << i << " " << time << " " << answer << endl;

            if(block < 0) continue;
            if(minTime > time || (minTime == time && answer < i)) minTime = time, answer = i;
        }

        return {minTime, answer};
    }
};

int main(){
    int N, M, B; cin >> N >> M >> B;
    Field f{N, M, B};

    int min{256};
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            int buf; cin >> buf;
            min = std::min(min, buf);
            f.v[i][j] = buf;
        }
    }
    pair<int, int> ans = f.timeMin(min);
    cout << ans.first << " " << ans.second << endl;
}