#include <iostream>
#include <vector>
using namespace std;

int main(){
    string buf; cin >> buf;
    vector<int> v(26);
    for(int i=0; i<buf.length(); ++i) v[buf[i] - 'a'] += 1;
    for(int i=0; i<25; ++i) cout << v[i] << " ";
    cout << v[25] << endl;
}