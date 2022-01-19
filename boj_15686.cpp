#include <iostream>
#include <vector>
#include <utility>
#include <memory.h>
using namespace std;

struct pos{
    int x, y;
};

int N, M, answer{1000000000};

vector<pos> home;
vector<pos> chicken;
bool visit[13];

int abs(int x){
    if(x < 0) return (-1) * x;
    return x;
}

int calc(){
    int res{0};
    int buf;
//    cout << "bufs : \n";

    for(pos i : home){
        int minimum{1000000000};
        for(int j=0; j < chicken.size(); ++j){
            if(visit[j]) continue;
            buf = abs(i.x - chicken[j].x) + abs(i.y - chicken[j].y);
//            cout << buf << "\n";
            minimum = min(minimum, buf);
        }
        res += minimum;
    }

//    cout << "res : " << res << "\n";
    return res;
}

void dfs(int idx, int size){
    if(size == M){
        answer = min(calc(), answer);
        return;
    }

    for(int i=idx; i < chicken.size(); ++i){
        if(visit[i]) continue;
        visit[i] = true;
        dfs(i, size - 1);
        visit[i] = false;
    }
}

int main(){
    memset(visit, false, sizeof visit);
    cin >> N >> M;

    int buf;
    for(int i=0; i < N; ++i){
        for(int j=0; j < N; ++j){
            cin >> buf;
            if(buf == 1) home.push_back({i, j});
            if(buf == 2) chicken.push_back({i, j});
        }
    }
    dfs(0, chicken.size());
    cout << answer << "\n";
}