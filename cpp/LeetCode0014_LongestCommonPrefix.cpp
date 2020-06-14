/*****************************************************
* 	 Filename: 	 LeetCode0014_LongestCommonPrefix.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 14. Longest Common Prefix	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-15T01:06:23.019Z+08:00
* 	 Modified: 	 2020-06-15T01:06:23.019Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include "mychiu.h"


using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if (strs.empty()) {
            return ret;
        }
        std::function<string(string,string)> getCommonPrefix;
        getCommonPrefix = [&](string a, string b)->string {
            string res = "";
            if (a.size() > b.size()) {
                return getCommonPrefix(b, a);
            }
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == b[i]) {
                    res.push_back(a[i]);
                } else {
                    break;
                }
            }
            return res;
        };
        ret = string(strs[0]);
        for (int i = 1; i < strs.size(); i++) {
            ret = getCommonPrefix(ret, strs[i]);
        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    vector<string> strs = {"aca","cba"};
    string ret = so.longestCommonPrefix(strs);
    cout << "ret = " << ret << endl;
    return 0;
}

