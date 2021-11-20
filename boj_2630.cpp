#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Paper{
public:
    int N;
    vector<vector<int>> v;
    int R, Rarea, B, Barea;

    Paper(int _N){
        N = _N, R = B = Rarea = Barea = 0;
        for(int i=0; i<N; ++i){
            v.push_back(vector<int>(N));
        }
    }

    int dnc(int x, int y, int k){
        if(k == 1)  return v[x][y];
        vector<int> res;
        int count[3] = {0, 0};

        for(int i=0; i<k; i += (k/2)){
            for(int j=0; j<k; j += (k/2)){
                int buf = (dnc(x + i, y + j, k / 2));
                count[buf] += 1;
            }
        }

        int p{0};
        for(int i=0; i<3; ++i)
            if(count[i] == 4) p = i;

            if(p != 0){
                if(k == N){
                    if(p == 1) R +=1;
                    else B += 1;
                }
                return p;
            }
            else{
                R += count[1];
                B += count[2];

                return 0;
            }
    }
};

int main(){
    int N; cin >> N;
    Paper p(N);

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int buf; cin >> buf;

            if(buf == 0) p.v[i][j] = 1;
            else p.v[i][j] = 2;
        }
    }

    p.dnc(0, 0, N);
    cout << p.R << "\n" << p.B << "\n";
}