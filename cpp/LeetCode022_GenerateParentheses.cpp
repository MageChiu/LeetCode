
#include<vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string test = string("");
        generateParenthesisString(test, n, n);
        vector<string> ret;
        return ret;
    }

    string generateParenthesisString(const string currentStr, int left, int right) {
        if (left <= 0 && right <= 0) {
            cout << currentStr << endl;
            return string(currentStr);
        }

        if (left == right ) {
            return generateParenthesisString(currentStr + "(", left - 1, right);
        } else if (left < right) {
            /* code */
            for (int i = right ; i > left; i--) {
                generateParenthesisString(currentStr + ")", left, i);
            }
            for (int i = left; i >= 0; i--) {
                generateParenthesisString(currentStr + "(", i, right);
            }
        } else {
            for (int i = left; i >= 0; i--) {
                generateParenthesisString(currentStr + "(", i, right);
            }
        }
        return string(currentStr);
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