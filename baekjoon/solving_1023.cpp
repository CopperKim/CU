// https://www.acmicpc.net/problem/1023

#include <iostream>

using namespace std;

int main() {
    int n, k; cin >> n >> k;

    int comb[51]; comb[1]=2;
    
    for(int i=2;i<=n;i++) {
        comb[i] = comb[i-1]*(2*i)*(2*i-1) / (i*i);
        // cout << comb[i] << ' ';
    }

    if (n%2 != 0) {
        int idx=0;
        int res[51];
        while(k!=1) {
            res[idx++] = k%2;
            k=k/2;
            cout << k << ' ';
        }
        cout << '\n';
        while(idx>0) cout << res[--idx] << ' ';
    }
}