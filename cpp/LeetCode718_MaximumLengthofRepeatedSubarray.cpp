/*****************************************************
* 	 Filename: 	 LeetCode718_MaximumLengthofRepeatedSubarray.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 718. Maximum Length of Repeated Subarray	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-07-01T01:21:08.886Z+08:00
* 	 Modified: 	 2020-07-01T01:21:08.886Z+08:00
* 	 Compiler: 	 g++
*****************************************************/


#include "mychiu.h"


#include <iostream>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp;
        dp.resize(A.size() + 1);
        for (int i = 0; i < dp.size(); i++) {
            dp[i].resize(B.size() + 1);
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] = 0;
            }
        }


        int max_len = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    if (dp[i+1][j+1] > max_len) {
                        max_len = dp[i+1][j+1];
                    }
                } else {
                    dp[i+1][j+1] = 0;
                }
            }
        }
        
        return max_len;

    }
};



int main(int argc, char const *argv[])
{
    /* code */
    /*
    Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
    */
    vector<int> A = {1,2,3,2,1};
    vector<int> B = {3,2,1,4,7};
    Solution so;
    int ret = so.findLength(A, B);
    cout << ret << endl;
    return 0;
}






