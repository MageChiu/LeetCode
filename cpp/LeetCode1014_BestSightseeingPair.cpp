/*****************************************************
* 	 Filename: 	 LeetCode1014_BestSightseeingPair.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 1014. Best Sightseeing Pair	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-17T00:18:08.434Z+08:00
* 	 Modified: 	 2020-06-17T00:18:08.434Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include "mychiu.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/**
 * 给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
 * 一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
 * 返回一对观光景点能取得的最高分。
 * A[i] + A[j] + i - j = A[i] + i + A[j] - j
 * */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ret = A[0] + 0;
        int left= A[0] + 0;
        for (int j = 1; j < A.size(); j++) {
            if (ret < left + A[j] - j) {
                ret = left + A[j] - j;
                cout << "ret j=" << j <<endl;
            }
            if (left < A[j] + j) {
                left = A[j] + j;
                cout << "left j=" << j <<endl;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> test_data = {8,1,5,2,6};
    Solution so;
    auto ret = so.maxScoreSightseeingPair(test_data);
    cout << ret << endl;
    return 0;
}
