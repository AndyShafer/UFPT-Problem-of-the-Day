#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    vector<vector<int>> time(N);
    for(int i = 0; i < N; i++) {
        time[i] = vector<int>(M);
        for(int j = 0; j < M; j++) {
            cin >> time[i][j];
        }
    }
    vector<vector<int>> tFinish(N);
    for(int i = 0; i < N; i++) {
        tFinish[i] = vector<int>(M);
        for(int j = 0; j < M; j++) {
            if(i == 0) {
                if(j == 0) tFinish[i][j] = time[i][j];
                else tFinish[i][j] = tFinish[i][j-1] + time[i][j];
            } else {
                if(j == 0) tFinish[i][j] = tFinish[i-1][j] + time[i][j];
                else tFinish[i][j] = max(tFinish[i][j-1], tFinish[i-1][j]) + time[i][j];
            }
        }
    }
    for(int i = 0; i < N; i++) {
        cout << tFinish[i][M-1] << " ";
    }
    cout << endl;
    return 0;
}
