#include <iostream>
// #include <vector>
#include <deque>
#include <stdio.h>
// #include <stack>

using namespace std;

int main() {
    int T; cin >> T;
    for(int i=0;i<T;i++) {
        char p[100003];
        cin >> p;

        bool isLeft = true;
        int j, len;

        deque<char> nums;
        cin >> len;
        getchar();
        for(j=0;j<len;j++) {
            getchar();
            nums.push_front(getchar());
        }

        j=0;

        while(p[j] != '\0') {
            if (nums.empty()) {
                cout << "error\n";
                break;
            }
            else if (p[j] == 'D') {
                if (isLeft) nums.pop_back();
                else nums.pop_front();
            }
            else {
                isLeft = !isLeft;
            }
            j++;
        }
        
        if(nums.empty()) continue;

        cout << '[';
        if (isLeft) {
            while (!nums.empty()) {
                cout << nums.back();
                nums.pop_back();
                if (!nums.empty()) cout << ',';
                else cout << "]\n";
            } 
        } else {
            while (!nums.empty()) {
                cout << nums.front();
                nums.pop_front();
                if (!nums.empty()) cout << ',';
                else cout << "]\n";
            } 
        }
    }   
}