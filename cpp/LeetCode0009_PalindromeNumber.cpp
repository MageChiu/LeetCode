/*****************************************************
* 	 Filename: 	 LeetCode0009_PalindromeNumber.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-10T01:04:08.410Z+08:00
* 	 Modified: 	 2020-06-10T01:04:08.410Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x >= 10 && x %10 == 0) {
            return false;
        }
        int res = 0;
        int tmp = x;
        
        while (tmp > 0 && res < tmp) {
            res *= 10;
            res += tmp % 10;
            if (res == tmp) {
                return true;
            }
            tmp /= 10;
            // cout << "res=" << res << ", tmp=" << tmp << endl;
        }
        if (res == tmp) {
            return true;
        } else {
            return false;
        }
    }
};


int main(int argc, char const *argv[])
{
    
    vector<int> test = {1, -1, 0, 2, 121, -121, 22, 33, 12, 10};
    vector<int> expec = {1, 0, 1, 1,  1,  0,     1,  1,  0,  0 };
    Solution so;
    // for (int i = 0; i < test.size(); i++) {
    //     bool res = so.isPalindrome(test[i]);
    //     if (res != expec[i]) {
    //         cout << "test for [" << test[i] << "], so is [" << so.isPalindrome(test[i]) << "]" << endl;
    //     }
        
    // }
    auto res = so.isPalindrome(10);
    cout << res << endl;
    return 0;
}

