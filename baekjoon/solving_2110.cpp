// https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; 
vector<long long> house;

int eval(int minlen) {
    int lastidx=0, curidx=0, count=0;
    while(curidx < house.size()) {
        if (house[curidx]-house[lastidx] < minlen) curidx++;
        else {count++; lastidx=curidx;}
    }
    return count;
}

void BS(int start, int end) {
    int mid = (start+end)/2, e = eval(mid);
    if (e == m) {
        while(eval(mid+1) == m) mid++;
        cout << mid;
        return;
    } else if (e < m) {
        BS(start, mid-1);
    } else {
        BS(mid+1, end);
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        house.push_back(input);
    }
    sort(&house[0], &house[n-1]);

    BS(1, house[n-1]);
}