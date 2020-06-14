/*****************************************************
* 	 Filename: 	 LeetCode1300_SumofMutatedArrayClosesttoTarget.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 1300. Sum of Mutated Array Closest to Target	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-14T19:01:49.039Z+08:00
* 	 Modified: 	 2020-06-14T19:01:49.039Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "mychiu.h"

using namespace std;


class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int pre_k = 0;
        int len = arr.size();
        int tmp_pre = 0 * len;
        int tmp_sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int k = pre_k + 1;
            int tmp = tmp_sum + k * (len - i);
            while (abs(tmp - target) < abs(tmp_pre - target) && k <= arr[i]) {
                pre_k = k;
                tmp_pre = tmp;
                k++;
                tmp = tmp_sum + k * (len - i);
            }
            tmp_sum += arr[i];
        } 
        return pre_k;
    }
};

/**
 * 4 9 3
 * 3 4 9
 * 
 **/

int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    vector<int> test_data = {60864,25176,27249,21296,20204};
    int target = 56803;
    int res = so.findBestValue(test_data, target);
    cout << res << endl;
    return 0;
}
