#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int size;
    cin >> size;        // 사이즈 입력받기

    static int sizer{size};
    int arr[sizer][sizer];
    
    unsigned int i{1}; //입력할 수
    int position{0};

    while(i <= sizer * sizer){  
    
        int j{position}, k{position}; // 위치 표현하는 변수들

        for(; j<size; j++){
            arr[k][j] = i++;
        }   // 달팽이 대입 구현

        j--, k++;
        for(; k<size; k++){
            arr[k][j] = i++;
        }

        k--, j--;
    
        for(; j>=position; j--){
            arr[k][j] = i++;
        }
    
        size--, position++, k--, j++;

        for(; k>=position; k--){
            arr[k][j] = i++;
        }
    }


    for(unsigned int row{0}; row < sizer; row++){
        for(unsigned int i : arr[row]){
            cout << setw(5)<< i ;
        }
        cout << endl;
    }
    
}