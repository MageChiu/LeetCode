/*
 * @Author: zhaopeng
 * @Date:   2020-07-17 02:49:49
 * @Last Modified by:   zhaopeng
 * @Last Modified time: 2020-07-17 03:05:01
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            cout << "s =" << s << ",e=" << e << endl;
            int mid = s + (e - s) / 2;
            if (nums[mid] >= target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> test = {1,3,5,6};
    int target = 1;
    Solution so;
    int ret = so.searchInsert(test, target);
    cout << ret << endl;
    return 0;
}

