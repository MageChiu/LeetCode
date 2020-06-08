/*****************************************************
* 	 Filename: 	 LeetCode1470_ShuffleTheArray.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-08T23:19:34.081Z+08:00
* 	 Modified: 	 2020-06-09T01:18:45.145Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        res.resize(nums.size());
        for (int i = 0; i < n; i++) {
            res[2 * i] = nums[i];
            res[2 * i + 1] = nums[i + n];
        }
        return res;
    }
};



int main()
{
    vector<int> test = {1,1,2,3 };
    Solution so;
    vector<int> test_res = so.shuffle(test, 2);
    for (int i = 0 ; i < test_res.size(); i++) {
        cout << test_res[i] << endl;
    }
    return 0;
}
