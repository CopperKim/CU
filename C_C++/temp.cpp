#include <iostream>
#include <vector>

using namespace std;

class Point {
public : 
    int x, y;
    Point(int k, int l) {x = k; y = l;}
};

Point addPoint(Point a, Point b) {
    return Point(a.x+b.x, a.y+b.y);
}

int main() {
    Point a(0, 0);
    Point b(0, 0);
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;

    Point res = addPoint(a, b);
    cout << res.x << res.y;
}