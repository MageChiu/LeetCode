
#include <vector>
#include "mychiu.h"
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() -1;
        while (i < j) {
            int tmp = numbers[i] + numbers[j];
            if (tmp < target) {
                i++;
            } else if (tmp > target) {
                j--;
            } else {
                return vector<int> {i + 1, j + 1};
            }
        }
        return vector<int>{};
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> test = {2,7,11,15};
    int target = 9;
    Solution so;
    vector<int> ret = so.twoSum(test, target);
    Common::print_data(ret);
    
    return 0;
}
