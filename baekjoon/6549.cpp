// https://www.acmicpc.net/problem/6549

#include <iostream>

using namespace std;

int n;
long long h[100006];

long long daq(int start, int end) {
    if (start == end) return h[start];
    int minidx=start;
    for(int i = start;i<=end;i++) if(h[i]<h[minidx]) minidx=i;
    if (minidx == start) return max(h[minidx]*(end-start+1), daq(minidx+1, end));
    if (minidx == end) return max(h[minidx]*(end-start+1), daq(start, minidx-1));
    return max(max(daq(start, minidx-1), daq(minidx+1, end)), h[minidx]*(end-start+1));
}

int main() {
    while(1) {
        cin >> n;
        if (n==0) return 0;
        for(int i=0;i<n;i++) cin >> h[i];
        cout << daq(0, n-1);
    }
}