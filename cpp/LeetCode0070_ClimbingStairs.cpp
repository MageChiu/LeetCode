/*****************************************************
* 	 Filename: 	 LeetCode0070_ClimbingStairs.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 70. Climbing Stairs	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-13T02:27:07.488Z+08:00
* 	 Modified: 	 2020-06-13T02:27:07.488Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        int f_1 = 1;
        int f_2 = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = f_1 + f_2;
            f_1 = f_2;
            f_2 = tmp;
        }
        return f_2;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> test_data = {2, 3};
    vector<int> test_res = {2, 3};
    Solution so;
    for (int i = 0; i < test_data.size(); i++) {
        int res = so.climbStairs(test_data[i]);
        cout << "test for " << test_data[i] << ", get " << res << endl;
    }
    return 0;
}

