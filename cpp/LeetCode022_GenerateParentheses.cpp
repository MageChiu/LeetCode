
#include<vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string test = string("");
        vector<string> ret;
        generateParenthesisString(ret, test, n, n);
        
        return ret;
    }

    int generateParenthesisString(vector<string> &data, string currentStr, int left, int right) {
        if (left <= 0 && right <= 0) {
            cout << currentStr << endl;
            data.push_back(currentStr);
            return 0;
        }

        if (right > left && right > 0) {
            generateParenthesisString(data, currentStr + ")", left, right - 1);
        }
        if (left > 0) {
            generateParenthesisString(data, currentStr + "(", left - 1, right);
        }
        return 0;
    }
};


int main() {
    int n = 3;

    Solution so;
    for (int i =1 ;i <= n; i++) {
        cout << i << endl;
        so.generateParenthesis(i);
    }
    return 0;
}