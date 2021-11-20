#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void triple(char num[]){
    int cnt{0};
    int sum{100};
    
    while(sum/10!=0){
        sum=0;
        for(int i=0;i<strlen(num); i++){
            sum=(int(num[i])-48)+sum;
        }

        sprintf(num, "%d", sum);
        cnt+=1;
    }
    cout<<cnt<<'\n';
    if(stoi(num)!=3&&stoi(num)!=6&&stoi(num)!=9)
        cout<<"NO";
    else
        cout<<"YES";
}


int main(){
    char num[1000001];
    cin>>num;
    triple(num);
}