#include <vector>

#include "mychiu.h"

using namespace std;

/**
 * 
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 
 *Note:
 *
 *The number of elements initialized in nums1 and nums2 are m and n respectively.
 *You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
 *Example:
 *
 *Input:
 *nums1 = [1,2,3,0,0,0], m = 3
 *nums2 = [2,5,6],       n = 3
 *
 *Output: [1,2,2,3,5,6]
 **/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m -1;
        int j = n -1;
        while (i >= 0 && j>=0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--]; 
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (i >= 0)
        {
            nums1[k--] = nums1[i--]; 
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    Solution so;
    so.merge(nums1, m, nums2, n);
    Common::print_data(nums1);
    return 0;
}
