/*
 * @Author: zhaopeng 
 * @Date: 2020-07-22 00:55:41 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-07-22 01:41:39
 */

#include <vector>
#include "mychiu.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int s = 0;
        int e = numbers.size() - 1;
        return minArray(numbers, s, e);
    }
    int minArray(vector<int>& numbers, int s, int e) {
        if ( s >= e) {
            return numbers[s];
        } 
        int m = s + (e -s)/2;
        if (numbers[m] < numbers[e]) {
            // 右侧有序，最小值在[s, m]
            // e = m;
            return minArray(numbers, s, m);
        } else if (numbers[m] > numbers[s]) {
            // 左侧有序，最小值在 s, (m, e]
            // s = m + 1;
            int r = minArray(numbers, m+1, e);
            if (r < numbers[s]) {
                return r;
            } else {
                return numbers[s];
            }
        } else {
            int l = minArray(numbers, s, m - 1);
            int r = minArray(numbers, m + 1, e);
            if (l < r) {
                return l;
            } else {
                return r;
            }
        }
        // return numbers[s];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> test= { 3, 4,0, 1, 2};
    Solution so;
    cout << so.minArray(test) << endl;  // 0
    test = {2,2,2,0,1};
    cout << so.minArray(test) << endl;  // 0
    test = {1,3,3};
    cout << so.minArray(test) << endl;         // 1
    test = {1, 2, 3, 4, 5};
    cout << so.minArray(test)   << endl;    // 1
    test = {3,3,1,3};
    cout << so.minArray(test) << endl;  //1
    test = {3,0,1,1,3};
    cout << so.minArray(test) << endl;
    return 0;
}


