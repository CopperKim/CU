#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001]={};

int main() {
    string S1; string S2;
    cin >> S1 >> S2;
    for(int i=0;i<S1.length();i++) {
        for(int j=0;j<S2.length();j++) {
            if (S1[i] == S2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    cout << dp[S1.length()][S2.length()];
}