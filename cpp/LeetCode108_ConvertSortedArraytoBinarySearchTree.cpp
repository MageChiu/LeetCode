#include <iostream>
#include <vector>
#include "mychiu.h"
#include <functional>


using namespace std;


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);    
    }
    TreeNode* sortedArrayToBST(const vector<int>& nums, int start, int end) {
        cout << "start=" << start << ",end=" << end << std::endl;
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};


int main(int argc, const char *argv[])
{
    vector<int> nums = {-10,-3,0,5,9};
    Solution so;
    TreeNode* tt = so.sortedArrayToBST(nums);
    Common::print_data(tt);
    return 0;
}

