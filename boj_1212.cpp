#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main(){
    string input;
    cin >> input;
    
    int buf = input[0] - '0';
    if(buf>=4) cout<<bitset<3>(buf);
    else if (buf >= 2) cout << bitset<2>(buf);
    else cout << bitset<1>(buf);

    for(int i=1; i<input.length(); i++){
        buf = input[i] - '0';
        cout << bitset<3>(buf);
    }
}