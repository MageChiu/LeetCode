/*****************************************************
* 	 Filename: 	 LeetCodeP017_04_MissingNumberLCCI.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 	17.04. Missing Number LCCI 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-12T10:07:47.469Z+08:00
* 	 Modified: 	 2020-06-12T10:07:47.469Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include "mychiu.h"
#include <iostream>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long sum = 0;
        for (int i = 0; i<nums.size(); i++) {
            sum += nums[i];
        }
        long n = nums.size();
        long expected_sum = n * (n+1) /2;
        return expected_sum - sum;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> test = {3, 0, 1};
    Solution so;
    cout << so.missingNumber(test) << endl;
    return 0;
}


