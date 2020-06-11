/*****************************************************
* 	 Filename: 	 LeetCode1431_KidsWithGreatestNumberofCandies.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 1431. Kids With the Greatest Number of Candies	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-11T10:19:22.598Z+08:00
* 	 Modified: 	 2020-06-11T10:19:22.598Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <vector>
#include <iostream>
#include "mychiu.h"

using namespace std;


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = 0;
        for (int i =0;i<candies.size(); i++) {
            if (m < candies[i]) {
                m = candies[i];
            }
        }
        vector<bool> res;
        res.resize(candies.size());
        for (int i =0;i<candies.size(); i++) {
            if (m - candies[i] <= extraCandies) {
                res[i] = true;
            } else {
                res[i] = false;
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> test ={12,1,12};
    int extraCandies = 10;
    Solution so;
    vector<bool> res = so.kidsWithCandies(test, extraCandies);
    Common::print_data(res);
    return 0;
}

