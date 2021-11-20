#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    double res = static_cast<double>(a) / static_cast<double>(b);
    cout << fixed << setprecision(9) << res << endl;
}