/*
 * @Author: zhaopeng 
 * @Date: 2020-08-02 23:45:33 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-08-03 00:05:28
 */

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        map<char, int> d;
        int p = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (d.find(c) == d.end()) {
                d[c] = i;
                
            } else {
                if (p < d[c]) {
                    p = d[c];
                }
                d[c] = i;
            }
            ret = ret > (i - p) ? ret : (i - p);
            if (ret >= 3) {
                cout << "i=" << i << endl;
            }
        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    string test = "abcabcbb";
    test = "pwwkew";
    test = "nnnnnnn";
    test = "abba";
    test = "bvbf";
    Solution so;
    cout << "test=" << test << endl;
    cout << so.lengthOfLongestSubstring(test) << endl;
    return 0;
}
