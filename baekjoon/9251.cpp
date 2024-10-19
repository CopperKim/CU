#include <iostream>

using namespace std;

int main() {
    char input1[1003], input2[1003];
    cin >> input1;
    cin >> input2;

    int LCS[1003]={};
    for(int i=0;input1[i]!='\0';i++) {
        int maxValue=0;
        for(int j=0;input2[j]!='\0';j++) {
            maxValue = max(LCS[j], maxValue);
            if (input2[j] == input1[i]) LCS[j] = maxValue+1;
        }
    }
    
    // for(int i=0;input1[i]!='\0';i++) cout << LCS[i] << ' ';

    int maxValue = 0;
    for(int i=0;input1[i]!='\0';i++) maxValue = max(maxValue, LCS[i]);
    cout << maxValue;
}