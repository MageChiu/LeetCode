/*****************************************************
* 	 Filename: 	 LeetCode0015_3Sum.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 15. 3Sum	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-12T00:15:11.801Z+08:00
* 	 Modified: 	 2020-06-12T00:15:11.801Z+08:00
* 	 Compiler: 	 g++
*****************************************************/
#include <iostream>

#include <map>
#include <vector>
#include "mychiu.h"
#include <set>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 2) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int target;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i >= 1) {
                if (nums[i] == nums[i-1]) {
                    continue;
                }
            }
            target = nums[i];
            int j = i+1;
            int k = nums.size() -1;
            while(j < k) {
                int tmp = nums[j] + nums[k];
                if (tmp < -target) {
                    j++;
                } else if (tmp > -target) {
                    k--;
                } else {
                    cout << "i=" << i << ",j=" << j << ",k=" << k << endl;
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    // vector<int> test_data = {-1, 0, 1, 2, -1, -4};
    vector<int> test_data = {0,0,0,0,0,0,0,0,0,0,0};
    Solution so;
    vector<vector<int>> result = so.threeSum(test_data);
    for (int i =0; i < result.size(); i++) {
        Common::print_data(result[i]);
    }
    return 0;
}

