#include <iostream>
#include <array>
using namespace std;

int main(){
    int seats;
    cin >> seats;

    static int peopls{seats};
    array<bool, 100> occupy;
    occupy.fill(false);

    int counter{0};
    int seatNum;
    for(unsigned int i=0; i<peopls; i++){
        cin >> seatNum;

        seatNum--;
        if(occupy[seatNum]){
            counter++;
        }
        else{
            occupy[seatNum] = true;
        }
    }

    cout << counter << endl;

}
