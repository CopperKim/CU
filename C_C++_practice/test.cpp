#include <iostream>
#include <deque>
using namespace std;
int main() {
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);

    cout << dq.front();
    cout << dq.back();
}