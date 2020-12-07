#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "mychiu.h"
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ret;
        vector<int> ele_lens;
        bool res = splitIntoFibonacci(S, 0, S.size()-1, ret, 0, ele_lens);
        return ret;
    }
    bool splitIntoFibonacci(string s, int begin, int end, vector<int>& ret, int pos, vector<int>& ele_lens) {
        if (begin > end) {
            if (ret.size() >= 3) {
                return true;
            } else {
                return false;
            }
        }
        int actual_begin = begin;
        int actual_end = end;
        if(pos >= 2) {
            actual_begin += max(ele_lens[pos-2], ele_lens[pos-1]) -1;
        }
        // if (pos < 2) {
        //     actual_end = end / 2;
        // }

        for(int i = actual_begin; i <= actual_end; i++) {
            // if (ret.size() < 3) {
            //     if (end - i < 3 - ret.size() - 1) {
            //         return false;
            //     }
            // }
            string cur_str = s.substr(begin, i - begin + 1);
            long cur_num = stol(cur_str);
            if (cur_num > 2147483647) {
                return false;
            }
            // if (cur_num == 0 && pos == 0) {
            //     return false;
            // }
            if(pos >= 2) {
                if (ret[pos-2] == cur_num - ret[pos-1]) {
                    ret.push_back(cur_num);
                    ele_lens.push_back(i - begin + 1);
                    bool res = splitIntoFibonacci(s, i + 1, end, ret, pos + 1, ele_lens);
                    if(res == true) {
                        return res;
                    } else {
                        ret.pop_back();
                        ele_lens.pop_back();
                    }
                }  
            } else {
                ret.push_back(cur_num);
                ele_lens.push_back(i - begin + 1);
                bool res = splitIntoFibonacci(s, i + 1, end, ret, pos + 1, ele_lens);
                if(res == true) {
                    return res;
                } else {
                    ret.pop_back();
                    ele_lens.pop_back();
                }
            }
            if(cur_str[0] == '0') {
                break;
            }
            
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    string test_str = "123456579";  // [123,456,579]
    auto res = so.splitIntoFibonacci(test_str);
    Common::print_data(res);
    test_str = "11235813"; // [1,1,2,3,5,8,13]
    test_str = "112358130"; //[]
    test_str = "1101111"; // [110, 1, 111] or [11, 0, 11, 11]
    res = so.splitIntoFibonacci(test_str);
    Common::print_data(res);
    test_str = "0123";  //[1,2,3]
    res = so.splitIntoFibonacci(test_str);
    Common::print_data(res);
    test_str = "1011";  // [1,0,1,1]
    res = so.splitIntoFibonacci(test_str);
    Common::print_data(res);
    test_str = "0000"; // [0, 0, 0, 0]
    res = so.splitIntoFibonacci(test_str);
    Common::print_data(res);
    test_str = "5511816597";  // 
    res = so.splitIntoFibonacci(test_str);
    Common::print_data(res);
    test_str = "214748364721474836422147483641";
    test_str = "214748364721474836422147483641";
    res = so.splitIntoFibonacci(test_str);
    Common::print_data(res);
    return 0;
}


