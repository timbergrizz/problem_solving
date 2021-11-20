#include <iostream>
using namespace std;

int main(){
    int date[2][3];
    bool luna[2];
    for(int n=0; n<2; n++){
        cin >> date[n][0] >> date[n][1] >> date[n][2];
        if(date[n][0] % 400 == 0) luna[n] = true;           //윤년 판단 알고리즘
        else if(date[n][0] % 100 == 0) luna[n] = false;
        else if(date[n][0] % 4 == 0) luna[n] = true;
        else luna[n] = false;
    }
    
    
}