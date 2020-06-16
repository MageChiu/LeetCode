/*****************************************************
* 	 Filename: 	 LeetCode859_BuddyStrings.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 	859. Buddy Strings 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-16T23:53:21.834Z+08:00
* 	 Modified: 	 2020-06-16T23:53:21.834Z+08:00
* 	 Compiler: 	 g++
*****************************************************/


#include "mychiu.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>


using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        int n = 0;
        bool flag = false;
        int arr[26] = {0};
        vector<int> na;
        vector<int> nb;
        for (int i = 0; i< A.size(); i++) {
            if (A[i] != B[i]) {
                n++;
                na.push_back(int(A[i] - 'a' + 1));
                nb.push_back(int(B[i] - 'a' + 1));
            }
            arr[A[i]-'a'] ++;
            if (arr[A[i]-'a'] >= 2) {
                flag = true;
            }
        }
        if (n == 2) {
            Common::print_data(na);
            Common::print_data(nb);
            if ((na[0] + na[1] == nb[0] + nb[1]) && (abs(na[0] - na[1]) == abs(nb[0] - nb[1]))) {
                return true;
            } else {
                return false;
            }
        } else if (n == 0)
        {
            /* code */
            return flag;
        } else
        {
            return false;
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    string test = "abcedefgbea";
    sort(test.begin(), test.end());
    cout << test << endl;
    string A = "ab", B = "ba";
    A = "ab", B = "ab";
    A = "aa", B = "aa";
    A = "aaaaaaabc", B = "aaaaaaacb";
    Solution so;
    auto ret = so.buddyStrings(A, B);
    cout << ret << endl;
    return 0;
}


