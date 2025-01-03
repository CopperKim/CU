#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    int *arr = (int*)calloc(n+2, sizeof(int));
    for(int i=1;i<=n;i++) {
        cin >> arr[i] >> arr[i+1]; // i번째 행렬 - arr[i] * arr[i+1]의 크기를 가짐
    }
    long long dp[501][501]={}; // dp[i][j] -> i번 행렬부터 j번 행렬까지 곱할 때 최소횟수
    for(int i=1;i<n;i++) dp[i][i+1] = arr[i] * arr[i+1] * arr[i+2];

    for(int space=2;space<=n;space++) {
        for(int start=1;start<=n-space;start++) { // start -> start + space
            vector<int> costs;
            for(int term = start+1;term<start+space;term++) {
                costs.push_back(dp[start][term] + dp[term+1][start+space] + arr[start] * arr[term+1] * arr[start+space+1]);
            }
            dp[start][start+space] = *min_element(costs.begin(), costs.end());
        }
    }

    cout << dp[1][n];
}