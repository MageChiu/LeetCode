/*****************************************************
* 	 Filename: 	 LeetCode350_IntersectionofTwoArraysII.cpp
* 	 Author: 	 zhaopeng
* 	 Description:350. Intersection of Two Arrays II
* 	 Version: 	 1.0
* 	 Created: 	 2020-07-13T22:53:56.843Z+08:00
* 	 Modified: 	 2020-07-13T22:53:56.843Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <vector>

#include "mychiu.h"
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ret;
        int i =0; 
        int j = 0;
        while (i < n1 && j < n2)
        {
            /* code */
            if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return ret;
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v1 = {1,2,2,1};
    vector<int> v2 = {2,2};
    Solution so;
    vector<int> ans = so.intersect(v1, v2);
    Common::print_data(ans);
    return 0;
}



