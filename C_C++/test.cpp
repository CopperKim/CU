#include <iostream> 
#include <stack>

using namespace std;

int main() {
    int N; cin >> N;
    for(int i=0;i<N;i++) {
        stack<char> S;
        char input[55];
        cin >> input;
        for(int j=0;input[j]!='\0';j++) {
            if(input[j] == '(') S.push('(');
            else if (S.empty()) {
                S.push('h');
                break;
            } 
            else S.pop();
        }
        if (S.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}