#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int m = k % n;
        cout << "m=" << m << endl;
        vector<int> tmp(nums.end() - m, nums.end());
        for (int i = nums.size() - 1; i >= m; i--) {
            nums[i] = nums[i-m];
        }
        for (int i =0; i<m; i++) {
            nums[i] = tmp[i];
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    vector<int> test = {-1,-100,3,99};
    int k = 2;
    so.rotate(test, k);
    for ( int i = 0; i < test.size(); i++) {
        cout << test[i] << endl;
    }
    return 0;
}


