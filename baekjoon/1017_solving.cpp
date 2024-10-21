// https://www.acmicpc.net/problem/1017

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, counts = 0; 
int *list, *nums;
bool curPass = false;
bool visited[53]={};

bool isPrime(int n) {
    for(int i=2;i*i<=n;i++) {
        if (n%i == 0) return false;
    }
    return true;
}

void link(int a, int b) {
    if (list[a] != 0 || list[b] != 0 ) {
        cout << "link error" << a << b << '\n';
    }
    list[a] = b;
    list[b] = a;
    counts++;
}

void unlink(int a, int b) {
    if (list[a] != b || list[b] != a) cout << "unlink error" << a << b << '\n';
    list[a] = 0;
    list[b] = 0;
    counts--;
}

void backtrack() {
    if (curPass) return;
    if (counts == n/2) {
        visited[list[1]] = true;
        curPass = true;
        return;
    }
    int minNotVisted;
    for(minNotVisted=1;list[minNotVisted]!=0;minNotVisted++);

    for(int i=minNotVisted+1;i<=n;i++) {
        if(list[i] != 0 || !isPrime(nums[i]+nums[minNotVisted])) continue;
        else {
            link(minNotVisted, i);
            backtrack();
            unlink(minNotVisted, i);
        }
    }
}

int main() {
    cin >> n;
    list = (int*)calloc(n+3, sizeof(int));
    nums = (int*)calloc(n+3, sizeof(int));
    for(int i=1;i<=n;i++) {
        cin >> nums[i];
    }

    for(int i=2;i<=n;i++) {
        link(1, i);
        if (!isPrime(nums[1]+nums[list[1]])) {
            unlink(1, i);
            continue;
        }
        curPass = false;
        backtrack();
        if(counts == n/2) {
            unlink(1, i);
            continue;
        }
        unlink(1, i);
    }
    
    vector<int> res;
    for(int i=1;i<=n;i++) {
        if (visited[i]) res.push_back(nums[i]);
    }
    if (res.empty()) {
        cout << -1;
        return 0;
    } else {
        sort(res.begin(), res.end());
        for(int a : res) cout << a << ' ';
    }
}