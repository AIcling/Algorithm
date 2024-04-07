#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int N = 0, M = 0;
    cin >> N >> M;
    vector<vector<int> > warehouse(N + 1, vector<int>(M));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> warehouse[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        int res = 0;
        for (int j = 1; j <= N; j++) {
            if (i != j) {
                bool flag = true;
                for (int k = 0; k < M; k++) {
                    if (warehouse[i][k]>=warehouse[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res = j;
                    break;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}