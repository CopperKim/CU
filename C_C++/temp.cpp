#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    int j=0, len, index = 1; cin >> len;
    vector<vector<char>> nums;
    string input; cin >> input;

    for(j=0;j<len;j++) {
        vector<char> addnum;
        while(input[index] != ',' && input[index] != ']') {
            addnum.push_back(input[index]);
            index++;
        }
        nums.push_back(addnum);
        index++;
    }
    
    for(j=0;j<len;j++) {
        for(char ch : nums[j]) {
            cout << ch << ' ';
        }
    }

    return 0;
}