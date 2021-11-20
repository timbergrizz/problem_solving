#include <iostream>
using namespace std;

int main(){
    bool paper[100][100] = {false, };

    int amount = 0, width = 0, height = 0;
    cin >> amount;

    const int amo = amount;
    
    for(int i=0; i<amo; i++){
        cin >> width >> height;
        for(unsigned int j = width; j < width+10; j++){
            for(unsigned int k = height; k < height + 10; k++){
                paper[j][k] = true;
            }
        }
    }

    int counter{0};
    for(unsigned int j = 0; j < 100; j++){
        for(unsigned int k = 0; k < 100; k++){
            if(paper[j][k]) counter++;
        }
    }

    cout << counter << endl;

    return 0;
}