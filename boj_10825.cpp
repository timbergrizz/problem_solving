#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Score{
public:
    string name;
    int kor, eng, mat;
    Score(){
        name = "", kor = eng = mat = 0;
    }
    Score(string _name, int _kor, int _eng, int _mat){
        name = _name, kor = _kor, eng = _eng, mat = _mat;
    }
};

bool s(Score A, Score B){
    if(A.kor != B.kor) return A.kor > B.kor;
    else if(A.eng != B.eng) return A.eng < B.eng;
    else if(A.mat != B.mat) return A.mat > B.mat;
    else{
        int v = A.name.compare(B.name);
        return v < 0;
    }
}

// <이 내림차순
// >이 오름차순
int main(){
    int N; cin >> N;
    vector<Score> v(N);

    for(int i=0; i<N; ++i){
        string n; int k, e, m;
        cin >> n >> k >> e >> m;
        v[i] = Score(n, k, e, m);
    }

    sort(v.begin(), v.end(), s);
    for(int i=0; i<N; ++i){
        cout << v[i].name << '\n';
    }
}

