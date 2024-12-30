// https://www.acmicpc.net/problem/2166

#include <iostream>
#include <stdio.h>

using namespace std;

class Point {
public :
    long double x, y; 
};

int main() {
    int n; cin >> n;
    Point *points = (Point*)calloc(n+1, sizeof(Point));
    long double area=0;
    for(int i=0;i<n;i++) {
        scanf("%Lf %Lf", &points[i].x, &points[i].y);
    }
    points[n].x = points[0].x;
    points[n].y = points[0].y;
    
    for(int i=0;i<n;i++) {
        // cout << (double)(points[i].x*points[i+1].y - points[i].y*points[i+1].x)/2 << '\n'; 
        area += (points[i].x*points[i+1].y - points[i].y*points[i+1].x)/2;
    }
    if (area<0) area*=-1;
    printf("%.1Lf\n", area);
}