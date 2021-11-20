#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string buf; cin >> buf;
    vector<string> v;

    for(int i=0; i<buf.size(); ++i) v.push_back(buf.substr(i));
    sort(v.begin(), v.end());
    for(int i=0; i<buf.size(); ++i) cout << v[i] << '\n';
}