/*
 * @Author: zhaopeng 
 * @Date: 2020-07-27 01:09:43 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-07-27 01:20:58
 */


#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        if ( i == s.size() ) {
            return true;
        } else {
            return false;
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    string s = "abc", t = "ahbgdc";
    Solution so;
    cout << so.isSubsequence(s, t) << endl;
    return 0;
}
