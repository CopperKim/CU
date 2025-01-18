#include <iostream>
#include <vector>
#include <utility>

#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

class line {
public : 
    pii p1, p2;

    line(int x1, int y1, int x2, int y2) {
        p1 = {x1, y1};
        p2 = {x2, y2};
    }
};

vector<line> V;

int CCW(pii p1, pii p2, pii p3) {
    return ((p1.x-p2.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p1.y-p2.y));
}

bool overlap(line l1, line l2) {
    int o1 = CCW(l1.p1, l1.p2, l2.p1)*CCW(l1.p1, l1.p2, l2.p2), o2 = CCW(l2.p1, l2.p2, l1.p1)*CCW(l2.p1, l2.p2, l1.p2);
    if (o1 == 0 && o2 == 0) {
        if (l1.p1 > l1.p2) swap(l1.p1, l1.p2);
        if (l2.p1 > l2.p2) swap(l2.p1, l2.p2);
        if (l1.p1 > l2.p2 || l1.p2 < l2.p1) return false;
        return true; 
    }
    
    else return (o1 <= 0 && o2 <= 0);
}

int *disjoint;

int find(int a) {
    if (disjoint[a] == a) return a;
    else return disjoint[a] = find(disjoint[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    disjoint[a] = b;
}

int main() {
    int n; cin >> n;
    disjoint = (int*)calloc(n+1, sizeof(int));
    for(int i=0;i<n;i++) disjoint[i] = i;

    for(int i=0;i<n;i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        V.push_back(line(x1, y1, x2, y2));
    }

    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if (find(i) == find(j)) continue;
            if (overlap(V[i], V[j])) {
                merge(i, j);
            }
        }
    }

    int res[3001]={}, M = 0, cnt=0;
    for(int i=0;i<n;i++) {
        res[find(i)] += 1;
    }
    for(int i=0;i<n;i++) {
        cout << disjoint[i] << '\n';
        if (res[i] != 0) cnt++;
        M = max(res[i], M);
    }
    cout << '\n';

    cout << cnt << '\n';
    cout << M;
}