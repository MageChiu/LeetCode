/*****************************************************
* 	 Filename: 	 LeetCode125_ValidPalindrome.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 	 125. Valid Palindrome
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-19T01:02:20.125Z+08:00
* 	 Modified: 	 2020-06-19T01:02:20.125Z+08:00
* 	 Compiler: 	 g++
*****************************************************/


#include "mychiu.h"
#include <iostream>

#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; 
        int j = s.size() -1;
        auto turn_low = [](char a) -> char {
            if (a <= 'Z' && a >= 'A') {
                return char(a - 'A' + 'a');
            } else {
                return a;
            }
        };
        auto check_char_nums = [](char a) -> bool {
            if (a <= 'Z' && a >= 'A') {
                return true;
            } else if (a <= 'z' && a >= 'a') {
                return true;
            } else if (a <= '9' && a >= '0') {
                return true;
            } else {
                return false;
            }
        };
        while(i < j) {
            char left = turn_low(s[i]);
            if (!check_char_nums(left)) {
                i++;
                continue;
            }
            char right = turn_low(s[j]);
            if (!check_char_nums(right)) {
                j--;
                continue;
            }
            if (left != right) {
                cout << "i=" << i << endl;
                cout << "j=" << j << endl;

                cout << "left=" << left << endl;
                cout << "right=" << right << endl;
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }

};


int main(int argc, char const *argv[])
{
    /* code */
    string test_str = "A man, a plan, a canal: Panama";
    test_str = "race a car";
    test_str = "aba";
    test_str = "abba";
    for (int i = 0; i< test_str.size(); i++) {
        cout << "[" << i << "]=" << test_str[i] << endl;
    }
    Solution so;
    cout << so.isPalindrome(test_str) << endl;
    
    return 0;
}
