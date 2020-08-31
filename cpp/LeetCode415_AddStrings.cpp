/*
 * @Author: zhaopeng 
 * @Date: 2020-08-03 00:08:26 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-08-03 00:21:07
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        if (num1.size() < num2.size()) {
            return addStrings(num2, num1);
        }
        ret.reserve(num1.size() + 1);
        int c = 0;
        int l1 = num1.size();
        int l2 = num2.size();
        int i = l1 -1 ;
        int j = l2 -1;
        while (i >= 0 && j >= 0) {
            int n = (num1[i] + num2[j] - '0' - '0' + c);
            ret.push_back(('0' + n % 10));
            c = n / 10;
            i--;
            j--;
        }
        while (i >= 0) {
            int n = (num1[i] - '0' + c);
            ret.push_back(('0' + n % 10));
            c = n / 10;
            i--;
        }
        while ( j >= 0) {
            int n = (num2[j] - '0' + c);
            ret.push_back(('0' + n % 10));
            c = n / 10;
            j--;
        }
        if ( c > 0) {
            ret.push_back(('0' + c));
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string n1 = "12345";
    string n2 = "111";
    Solution so;
    cout << so.addStrings(n1, n2) << endl;
    return 0;
}
