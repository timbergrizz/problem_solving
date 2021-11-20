//boj_11651
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortPos(vector<int> A, vector<int> B){
    if(A[1] != B[1]){
        return A[1] < B[1];
    }
    else{
        return A[0] < B[0];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int positionNum; cin >> positionNum;
    vector<vector<int>> positions;

    for(int i = 0; i < positionNum; ++i){
        int x, y ; cin >> x >> y;
        positions.push_back(vector<int> {x, y});
    }

    sort(positions.begin(), positions.end(), sortPos);

    for(int i=0; i < positionNum; ++i){
        cout << positions[i][0] << " " << positions[i][1] << "\n";
    }
}