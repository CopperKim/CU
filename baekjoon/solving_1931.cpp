// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return true;
    if (a.first == b.first && a.second < b.second) return true;
    return false;
}

int main() {
    int n; cin >> n;
    pair<int, int> time[100006];
    for(int i=0;i<n;i++) {
        int input1, input2; cin >> input1 >> input2;
        time[i]={input1, input2};
    }
    sort(&time[0], &time[n], cmp);
    for(int i=0;i<n;i++) {
        cout << time[i].first << ' ' << time[i].second << '\n';
    }
    int idx=0, count=0, end=time[0].second;
    for(int i=0;i<n;i++) {
        if (end<=time[idx].first) {
            count++;
            end = time[idx].second;
        }
    }
    cout << count;
}