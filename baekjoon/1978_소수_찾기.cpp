#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n==1) return false;
    for(int i=2;i*i<=n;i++) {
        if (n%i==0) return false;
    }
    return true;
}

int main() {
    int n; cin >> n;
    int count=0;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        if (isPrime(input)) count++;
    }
    cout << count;
}