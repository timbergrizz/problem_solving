#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    const int MM{M};

    map <string, int> pokemon;
    map <int, string> pokemon2;

    string buffer;

    for(int i=0; i<N; i++){ // 포켓몬 이름 입력
        cin >> buffer;
        pokemon.insert(make_pair(buffer, i+1));
        pokemon2.insert(make_pair(i+1, buffer));

    }

    string buf[MM];

    for(int i=0; i< MM; i++){ //문제 입력
        cin >> buf[i];
    }

    for(int i=0; i<MM; i++){    // 정답 도출
        if(buf[i][0] <= 57 && buf[i][0] >=48){
            int ind = stoi(buf[i]);
            cout << pokemon2.find(ind) -> second << "\n";
        }
        else{
            cout << pokemon.find(buf[i]) -> second << "\n";
        }
    }
}