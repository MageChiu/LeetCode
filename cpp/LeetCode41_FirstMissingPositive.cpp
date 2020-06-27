/*****************************************************
* 	 Filename: 	 LeetCode41_First MissingPositive.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 41. First Missing Positive	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-27T20:59:51.829Z+08:00
* 	 Modified: 	 2020-06-27T20:59:51.829Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include "mychiu.h"
#include <iostream>


using namespace std;



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            Common::print_data(nums);
            if (nums[i] > n || nums[i] <= 0) {
                nums[i] = 0;
                i++;
            } else if (nums[i] == i + 1) {
                i++;
            } else {
                int j = nums[i];
                if (j != nums[j-1]) {
                    nums[i] = nums[j-1];
                    nums[j-1] = j;
                } else {
                    nums[i] = 0;
                    i++;
                }
                
            }
        }
        for (int k = 0; k < n; k++) {
            if (nums[k] == 0) {
                return k+1;
            }
        }
        return n + 1;
    }
};

/*
for case:
{1, 1, 1}

[1 , 1 , 1 ]
[1 , 1 , 1 ]
[1 , 0 , 1 ]


*/


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> test_data = {3,4,-1,1};
    // test_data = {2,1,0};
    test_data = {1, 1, 1};
    Solution so;
    int ret = so.firstMissingPositive(test_data);
    cout << ret << endl;
    return 0;
}

