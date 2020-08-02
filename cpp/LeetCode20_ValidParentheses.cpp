/*
 * @Author: zhaopeng 
 * @Date: 2020-07-28 23:59:00 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-07-29 00:07:15
 */

#include <stack>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> _d;
        for (int i = 0; i< s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                _d.push(s[i]);
            } else {
                if (_d.empty()) {
                    return false;
                } else {
                    if (s[i] == ')') {
                        if (_d.top() == '(') {
                            _d.pop();
                        } else {
                            return false;
                        }
                    } else if (s[i] == ']') {
                        if (_d.top() == '[') {
                            _d.pop();
                        } else {
                            return false;
                        }
                    } else if (s[i] == '}') {
                        if (_d.top() == '{') {
                            _d.pop();
                        } else {
                            return false;
                        }
                    } 
                }
            }
        }
        if (_d.empty()) {
            return true;
        } else {
            return false;
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    string test = "]";
    cout << so.isValid(test) << endl;
    return 0;
}
