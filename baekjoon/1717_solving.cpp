// https://www.acmicpc.net/problem/1717

#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int* arr = (int*)malloc((n+3)*sizeof(int));
    for(int i=1;i<=n;i++) arr[i]=i;
    int p, a, b;
    for(int i=0;i<m;i++) {
        cin >> p >> a >> b;
        if (p==0) {
            if (arr[a] == arr[b]) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else {
            if(arr[a] == a) arr[a] = arr[b];
            else if (arr[b] == b) arr[b] = arr[a];
        }
    }
}