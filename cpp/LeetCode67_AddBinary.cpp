/*****************************************************
* 	 Filename: 	 LeetCode67_AddBinary.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 67. Add Binary	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-23T00:55:56.115Z+08:00
* 	 Modified: 	 2020-06-23T00:55:56.115Z+08:00
* 	 Compiler: 	 g++
*****************************************************/


#include "mychiu.h"
#include <stack>
#include <iostream>

using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            return addBinary(b, a);
        }
        stack<char> tmp;
        bool flag = false;
        int c = 0;
        int i = a.size() -1;
        int j = b.size() - 1;
        auto turn_num = [](char k)->int {
            return int(k-'0');
        };
        while (j >= 0) {
            int a_i = turn_num(a[i]);
            int b_j = turn_num(b[j]);
            int p = a_i ^ b_j ^c;
            if (p == 0) {
                tmp.push('0');
            } else {
                tmp.push('1');
            }
            if ((a_i + b_j + c) >= 2) {
                c = 1;
            } else {
                c = 0;
            }
            i--;
            j--;
        }
        while (i >= 0) {
            int a_i = turn_num(a[i]);
            int p = a_i ^c;
            if (p == 0) {
                tmp.push('0');
            } else {
                tmp.push('1');
            }
            if ((a_i + c) >= 2) {
                c = 1;
            } else {
                c = 0;
            }
            i--;
        }
        if ( c == 1) {
            tmp.push('1');
        }
        string res;
        res.reserve(tmp.size());
        while (!tmp.empty()) {
            res.push_back(tmp.top());
            tmp.pop();
        }
        return res; 
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string a = "100";
    string b = "110010";
    a = "11";
    b = "1";
    Solution so;
    cout << so.addBinary(a, b) << endl;
    return 0;
}


