//boj_1764
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int N, M; cin >> N >> M;

    unordered_map<string, bool> m;
    vector<string> unknown;

    for(int i=0; i< N; ++i){
        string str; cin >> str;
        m.insert(pair<string, bool>(str, true));
    }
    for(int i=0; i< M; ++i){
        string str; cin >> str;
        unordered_map<string, bool>::const_iterator it = m.find(str);
        if(it != m.end()){
            unknown.push_back(str);
        }
    }

    sort(unknown.begin(), unknown.end());
    cout << unknown.size() << endl;
    for(int i=0; i < unknown.size(); ++i){
        cout << unknown[i] << endl;
    }
}
