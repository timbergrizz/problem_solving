#include <iostream>
using namespace std;

int main(){
    int width, height;
    cin >> width >> height;
    
    const int wid{width};
    const int hei{height};
    int rectangle[wid][hei];
    int counter[51] = {0, };

    
    for(int i =0; i<width; i++){
        for(int j = 0; j < height; j++){
            cin >> rectangle[i][j];
            counter[rectangle[i][j]]++;
        }
    }
    int result{0};
    for(int i=1; i <= 50 && counter[i] >= 4; i++){
        int k{0}, j{0};
        for(; k<width; k++){
            for(; j < height; j++){
                cout << rectangle[k][j];
                if(rectangle[k][j] == i) break;
            }
            cout << j;
            if(rectangle[k][j] == i) break;
        }
        for(int l = k; l < width && rectangle[l][j] == i; l++){
            cout << l;
            int length = l - k;
            if(rectangle[k][j+length] == i && rectangle[k+length][i+length] == i){
                if(result < (length * length)) result = length * length;
            }
        }
    }
    cout << result << endl;    
}