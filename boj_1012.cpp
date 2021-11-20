//boj_1012
#include <iostream>
#include <vector>
using namespace std;

class Field{
public:
    vector<vector<int>> v;

    int width, height;
    int result;

    Field(int _width, int _height){
        width = _width, height = _height;
        result = 0;

        for(int i=0; i<width; ++i){
            v.push_back(vector<int>(height));
        }
    }

    void setPos(int x, int y){
        v[x][y] = 1;
    }

    int find(){
        for(int i=0; i<v.size(); ++i){
            for(int j=0; j<v[i].size(); ++j){
                if(v[i][j] == 1){
                    ++result;
                    dfs(i, j);
                }
            }
        }

        return result;
    }

    void dfs(int x, int y){
        v[x][y] = 0;

        if(x > 0){
            if(v[x-1][y] == 1){
                dfs(x-1, y);
            }
        }

        if(x < width - 1){
            if(v[x+1][y] == 1){
                dfs(x+1, y);
            }
        }

        if(y > 0){
            if(v[x][y-1] == 1){
                dfs(x, y-1);
            }
        }

        if(y < height - 1){
            if(v[x][y+1] == 1){
                dfs(x, y+1);
            }
        }
    }
};

int main(){
    int cases; cin >> cases;

    for(int caseNum = 0; caseNum < cases; ++caseNum){
        int M, N, K; cin >> M >> N >> K;
        Field field{M, N};

        for(int i=0; i<K; ++i){
            int x, y; cin >> x >> y;
            field.setPos(x, y);
        }

        cout << field.find() << endl;
    }
}