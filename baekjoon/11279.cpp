// https://www.acmicpc.net/problem/11279

#include <iostream>

using namespace std;

int maxheap[100006];
int count=0;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void addData(int data) {
    int idx = ++count;
    maxheap[idx] = data;
    while(idx > 1 && maxheap[idx/2] < maxheap[idx]) {
        swap(maxheap[idx], maxheap[idx/2]);
        idx = idx/2;
    }
    return;
}

void deleteData() {
    if (count == 0) {
        cout << 0 << '\n';
        return;
    }
    int delData = maxheap[1];
    maxheap[1] = 0;
    swap(maxheap[1], maxheap[count--]);
    int idx=1; 
    while(idx < count) {
        if (maxheap[idx] < maxheap[2*idx]) {
            swap(maxheap[idx], maxheap[2*idx]);
            idx = 2*idx;
            } 
        else if (maxheap[idx] < maxheap[2*idx+1]) {
            swap(maxheap[idx], maxheap[2*idx+1]);
            idx = 2*idx+1;
        }
        else break;
        } 
    cout << delData << '\n';
    return;
}

int main() {
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        if (input == 0) deleteData();
        else addData(input); 
        for(int j=1;j<=n;j++) cout << maxheap[j] << ' ';
        cout << count << '\n';
    }
}