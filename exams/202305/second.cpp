#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> allBoards; 

    for (int i = 0; i < n; i++) {
        string chess;
        chess.reserve(64); 
        for (int j = 0; j < 8; j++) {
            string line;
            cin >> line;
            chess += line; 
        }
        int cnt = count(allBoards.begin(), allBoards.end(), chess);
        allBoards.push_back(chess); 
        cout << cnt + 1 << endl; 
    }

    return 0;
}