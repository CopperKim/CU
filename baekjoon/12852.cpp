#include <iostream>
#include <queue>
#include <vector>
// #include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    int visited[1000007];
    visited[N] == -1;

    queue<int> Q;
    Q.push(N);

    while(visited[1] == 0) {
        N = Q.front();
        Q.pop();
        if( N % 3 == 0 ) {
            Q.push(N/3);
            visited[N/3] = N;
        }
        if( N % 2 == 0 ) {
            Q.push(N/2) = N;
            visited[N/2] = N;
        }
        Q.push(N-1);
        visited[N-1] = N;
    }
    
    vector<int> result;

    int idx=1;
    while(visited[idx] != -1) {
        result.push_back(idx);
        idx = visited[idx];
    }

    cout << result.size() << '\n';
    for(int i=result.size()-1;i>=0;i--) {
        cout << result[i] << ' ';
    }
}