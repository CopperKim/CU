// https://www.acmicpc.net/problem/1300

#include <iostream>

using namespace std;

int n, k; 

int eval(int m) {
    int count=0;
    for(int i=1;i<=n;i++) {
        count += min(n, m/n);
    }
    return count;
}

void BS(int start, int end) {
    
}

int main() {
    cin >> n >> k;
    cout << eval(6) << '\n';
}