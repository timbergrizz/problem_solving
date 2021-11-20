#include <iostream>
using namespace std;

int alg1(int num1){
    int counter{0};
    while(num1 != 1){
        if(num1 == 0) break;
        else if(num1%3 == 0) num1 /= 3;
        else if((num1-1)%3 == 0) num1--;
        else if(num1%2 == 0) num1 /= 2;
        else num1--;
        counter++;
    }
    return counter;
}

int alg2(int num2){
    int counter2{0};

    while(num2!=1){
        if(num2 == 0) break;
        else if(num2%3 == 0) num2 /= 3;
        else if(num2%2 == 0) num2 /= 2;
        else if((num2-1)%3 == 0) num2--;
        else num2--;
        counter2++;
    }
    return counter2;

}

int main(){
    unsigned int numFir;
    unsigned int counter1{0};
    unsigned int counter2{0};

    cin >> numFir;

    counter1 = alg1(numFir);
    counter2 = alg2(numFir);

    (counter1 <= counter2) ? cout << counter1 : cout << counter2;
    cout << endl;
    
    return 0;
}