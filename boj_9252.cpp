#include <iostream>
#include <string>

using namespace std;

int lcs[1001][1001]{0,};
string buf1, buf2;

string dfs(int i, int j) {
    if(lcs[i][j] == 0) return "";
    string ret;

    if (i - 1 != 0 && lcs[i - 1][j] == lcs[i][j]) ret += dfs(i - 1, j);
    else if (j - 1 != 0 && lcs[i][j - 1] == lcs[i][j]) ret += dfs(i, j - 1);
    else if (i >= 0 && j >= 0){
        ret += buf1[i-1];
        ret = dfs(i - 1, j - 1) + ret;
    }

    return ret;
}


int main() {
    cin >> buf1 >> buf2;
    int len1 = buf1.length(), len2 = buf2.length();

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (buf1[i - 1] == buf2[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    cout << lcs[len1][len2] << "\n";
    cout << dfs(len1, len2) << "\n";
}