#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str; cin >> str;
    int B; cin >> B;
    long long N{0};
    long long b{1};
    for(int i = str.size() - 1; i >= 0; --i){
        if(str[i] >= 'A' && str[i] <= 'Z') N += b * (str[i] - 'A' + 10);
        else N += b * (str[i] - '0');
        b *= B;
    }
    cout << N << endl;
}