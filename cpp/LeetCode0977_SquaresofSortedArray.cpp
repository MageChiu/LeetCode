/*****************************************************
* 	 Filename: 	 LeetCode0977_SquaresofSortedArray.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 977. Squares of a Sorted Array	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-10T23:39:25.620Z+08:00
* 	 Modified: 	 2020-06-10T23:39:25.620Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include "mychiu.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int pos = 0;
        int m = 10000;
        for (int i = 0; i < A.size(); i++) {
            if (abs(A[i]) <= m) {
                pos = i;
                m = abs(A[i]);
            } else {
                break;
            }
        }
        Common::print_data(pos);
        vector<int> res;
        res.reserve(A.size());
        int l = pos - 1;
        int r = pos;
        while (l >=0 && r < A.size()) {
            if (abs(A[l]) < A[r]) {
                res.push_back(A[l] * A[l]);
                l--;
            } else {
                res.push_back(A[r] * A[r]);
                r++;
            }
        }
        while (l >=0) {
            res.push_back(A[l] * A[l]);
            l--;
        }
        while (r < A.size()) {
            res.push_back(A[r] * A[r]);
            r++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> test = {-3,-3,-2,1};
    Solution so;
    vector<int> res = so.sortedSquares(test);
    Common::print_data(res);
    // test = {-7,-3,2,3,11};
    // res = so.sortedSquares(test);
    // Common::print_data(res);
    return 0;
}
