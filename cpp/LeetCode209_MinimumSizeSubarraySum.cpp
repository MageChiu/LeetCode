/*****************************************************
* 	 Filename: 	 LeetCode209_MinimumSizeSubarraySum.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 	209. Minimum Size Subarray Sum 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-28T00:05:34.092Z+08:00
* 	 Modified: 	 2020-06-28T00:05:34.092Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include "mychiu.h"
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int i = 0;
        int min_len = n + 1;
        int sum = 0;
        int j = i;
        while(i < n && j < n) {
            while (j < n && sum < s)
            {
                sum += nums[j];
                j++;
            }
            while ( i <= j && sum >= s) {
                sum -= nums[i];
                if (min_len > j - i) {
                    min_len = j - i;
                }
                i++;     
            }
            
        }
        if (min_len != n + 1) {
            return min_len;
        } else {
            return 0;
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    int s = 7;
    vector<int>  nums = {2,3,1,2,4,3};
    Solution so;
    int ret = so.minSubArrayLen(s, nums);
    Common::print_data(ret);
    return 0;
}

