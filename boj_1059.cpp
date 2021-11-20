#include <iostream>
using namespace std;
int min(int arr[], const int size){
    int result = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] < result) result = arr[i];
    }
    return result;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    const int M{m};
    int string[2][M];

    for(int i=0; i<M; i++) cin >> string[0][i] >> string[1][i];
    int string_min[2];
    string_min[1] = min(string[1], M);
    string_min[0] = min(string[0], M);
    if(string_min[1] * 6 < string_min[0]) string_min[0] = string_min[1] * 6;
    

    int result;
    result = string_min[0] * (n / 6);

    if(string_min[0] < string_min[1] * (n % 6)) result += string_min[0];
    else result += string_min[1] * (n % 6);

    cout << result << endl;
}