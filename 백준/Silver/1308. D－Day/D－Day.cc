#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=1; i <= END; ++i)
using namespace std;

struct day {
    int year, month, day;
};

int month_arr[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

bool check(int year){
    if(!(year % 4)) {
        if(!(year % 100) && (year % 400)) return false;
        else return true;
    }
    return false;
}

int days(day d) {
    int y = d.year - 1;
    int leap_year = y / 4 - (y / 100) + (y / 400);
    int ret{0};
    ret += y * 365 + leap_year + month_arr[d.month - 1] + d.day;

    if(check(d.year) && d.month > 2) ret += 1;

    return ret;
}

int main() {
    day start{0, 0, 0}, end{0, 0, 0};

    cin >> start.year >> start.month >> start.day;
    cin >> end.year >> end.month >> end.day;

    if ((end.year - start.year > 1000) || (end.year - start.year == 1000 && end.month >= start.month && end.day >= start.day)) cout << "gg";
    else {
        cout << "D-" << days(end) - days(start);
    }
}