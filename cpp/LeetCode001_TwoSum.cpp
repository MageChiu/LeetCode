/*******************************************
 * FileNmae: cpp/LeetCode001_TwoSum.cpp
 * Author: Charles
 * Data: 11/4/2019, 1:29:43 AM
 * Data: f11a43aring
 ******************************************/
#include "leetcode_header.h"


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> testMap;
        for (int i = 0; i < nums.size(); i++) {
            int find_dest = target - nums[i];
            if (testMap.find(find_dest) == testMap.end()) {
                testMap[nums[i]] = i;
            }else {
                return vector<int> {testMap[find_dest], i};
            }
        }
        return vector<int> {0};
    }
};

int main()
{
    vector<int> testNums = { 2, 7, 11, 15 };
    int target = 9;
    Solution so;
    vector<int> result = so.twoSum(testNums, target);
    for (int i : result) {
        cout << i << endl;
    }
    return 0;
}

