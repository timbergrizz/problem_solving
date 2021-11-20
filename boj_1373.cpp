#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str; cin >> str;
    reverse(str.begin(), str.end());
    vector<int> v;

    for(int i=0; i < str.size(); i += 3){
        int buf{0}, n{1};

        for(int j=0; j<=2 && i + j < str.size(); ++j) {
            buf += (str[i+j] - '0') * n;
            n *= 2;
        }
        v.push_back(buf);
    }

    for(int i=v.size() -1; i >= 0; --i){
        cout << v[i];
    }

    cout << endl;
}