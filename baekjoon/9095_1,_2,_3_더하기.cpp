#include <iostream>

using namespace std;

int main() {
    int arr[12];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int i=4;i<12;i++) {
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }

    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        cout << arr[input] << '\n';
    }
}